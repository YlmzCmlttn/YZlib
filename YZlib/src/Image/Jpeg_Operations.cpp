#include "Image/Jpeg_Operations.h"
#include "Core/Debug.hpp"
#include <fstream>
#include <jpeglib.h>
namespace YZlib{
    const static size_t JPEG_BUF_SIZE = 16384;
    struct my_source_mgr {
        struct jpeg_source_mgr pub;
        std::istream* is;
        JOCTET*       buffer;
    };
    static void my_init_source(j_decompress_ptr cinfo){        
        (void)(sizeof(cinfo));
    }
    static boolean my_fill_input_buffer(j_decompress_ptr cinfo) {
        my_source_mgr* src = (my_source_mgr*)cinfo->src;

        src->is->read((char*)src->buffer, JPEG_BUF_SIZE);
        size_t bytes = src->is->gcount();
        if (bytes == 0) {            
            src->buffer[0] = (JOCTET) 0xFF;
            src->buffer[1] = (JOCTET) JPEG_EOI;
            bytes = 2;
        }
        src->pub.next_input_byte = src->buffer;
        src->pub.bytes_in_buffer = bytes;
        return TRUE;
    }
    static void my_skip_input_data(j_decompress_ptr cinfo, long num_bytes) {
        my_source_mgr* src = (my_source_mgr*)cinfo->src;
        if (num_bytes > 0) {
            while (num_bytes > (long)src->pub.bytes_in_buffer) {
                num_bytes -= (long)src->pub.bytes_in_buffer;
                my_fill_input_buffer(cinfo);
            }
            src->pub.next_input_byte += num_bytes;
            src->pub.bytes_in_buffer -= num_bytes;
        }
    }
    static void my_term_source(j_decompress_ptr cinfo) {
        // must seek backward so that future reads will start at correct place.
        my_source_mgr* src = (my_source_mgr*)cinfo->src;
        src->is->clear();
        src->is->seekg( src->is->tellg() - (std::streampos)src->pub.bytes_in_buffer );
    }
    static void my_set_source_mgr(j_decompress_ptr cinfo, std::istream& is) {
        my_source_mgr* src;
        if (cinfo->src == NULL) {
        cinfo->src = (struct jpeg_source_mgr *)(*cinfo->mem->alloc_small)
            ((j_common_ptr) cinfo, JPOOL_PERMANENT, sizeof(my_source_mgr));
        
        }
        src = (my_source_mgr*) cinfo->src;
        src->buffer = (JOCTET *)(*cinfo->mem->alloc_small)
            ((j_common_ptr) cinfo, JPOOL_PERMANENT, JPEG_BUF_SIZE*sizeof(JOCTET));
        src->is = &is;
        src->pub.init_source = my_init_source;
        src->pub.fill_input_buffer = my_fill_input_buffer;
        src->pub.skip_input_data = my_skip_input_data;
        src->pub.resync_to_restart = jpeg_resync_to_restart; /* use default method */
        src->pub.term_source = my_term_source;
        src->pub.bytes_in_buffer = 0;
        src->pub.next_input_byte = 0;
    }

    Image_ readjpegimage(const std::string& file_name){
        struct jpeg_decompress_struct cinfo; 
        struct jpeg_error_mgr jerr;
        cinfo.err = jpeg_std_error(&jerr); 
        jpeg_create_decompress(&cinfo);        
        std::ifstream ifs;
        ifs.open(file_name,std::ios::binary);
        if(!(ifs)){
            ERROR(file_name," couldn't open");
            abort();
        } 
        my_set_source_mgr(&cinfo, ifs);
        int r = jpeg_read_header(&cinfo, TRUE);
        Matrix_<unsigned char> data;
        if (r != JPEG_HEADER_OK) {
            ERROR("Failed to read JPEG header.");
        }else if (cinfo.num_components != 3 && cinfo.num_components != 1){
            ERROR("Unsupported number of color components: ",cinfo.num_components);
        }else{
            jpeg_start_decompress(&cinfo);
            data = Matrix_<unsigned char>(cinfo.output_height,cinfo.output_width*cinfo.output_components);

            JSAMPARRAY imageBuffer = (*cinfo.mem->alloc_sarray)((j_common_ptr)&cinfo, JPOOL_IMAGE, 
                                                                cinfo.output_width*cinfo.output_components, 1);
            for (uint y = 0; y < cinfo.output_height; y++) {
                jpeg_read_scanlines(&cinfo, imageBuffer, 1);
                for (unsigned int j = 0; j < cinfo.output_width*cinfo.output_components; j++) {
                    data(y,j)=imageBuffer[0][j];
                }                
            }
            jpeg_finish_decompress(&cinfo);
        }
        jpeg_destroy_decompress(&cinfo); 
        return Image_((size_t)cinfo.output_width,(size_t)cinfo.output_height,cinfo.output_components,std::move(data));

    }
    struct my_destination_mgr {
        struct jpeg_destination_mgr pub; /* public fields */
        std::ostream* os; /* target stream */
        JOCTET * buffer;	   /* start of buffer */
    };
    
    void my_init_destination (j_compress_ptr cinfo) {
        my_destination_mgr* dest = (my_destination_mgr*) cinfo->dest;
        dest->buffer = (JOCTET *)(*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
                                                            JPEG_BUF_SIZE * sizeof(JOCTET));
        dest->pub.next_output_byte = dest->buffer;
        dest->pub.free_in_buffer = JPEG_BUF_SIZE;
    }

    boolean my_empty_output_buffer(j_compress_ptr cinfo) {
        my_destination_mgr* dest = (my_destination_mgr*)cinfo->dest;
        
        dest->os->write((const char*)dest->buffer, JPEG_BUF_SIZE);
        if (dest->os->fail()) {
            ERROR("Couldn't write entire jpeg buffer to stream.");
        }
        dest->pub.next_output_byte = dest->buffer;
        dest->pub.free_in_buffer = JPEG_BUF_SIZE;
        return TRUE;
    }

    void my_term_destination (j_compress_ptr cinfo) {
        my_destination_mgr* dest = (my_destination_mgr*) cinfo->dest;
        size_t datacount = JPEG_BUF_SIZE - dest->pub.free_in_buffer;
        
        /* Write any data remaining in the buffer */
        if (datacount > 0) {
            dest->os->write((const char*)dest->buffer, datacount);
            if (dest->os->fail()) {
                ERROR("Couldn't write remaining jpeg data to stream.");
            }
        }
        dest->os->flush();
    }

    void my_set_dest_mgr(j_compress_ptr cinfo, std::ostream& os) {
        my_destination_mgr* dest;

        if (cinfo->dest == NULL) {	/* first time for this JPEG object? */
            cinfo->dest = (struct jpeg_destination_mgr *)
                (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_PERMANENT,
                                            sizeof(my_destination_mgr));
        }

        dest = (my_destination_mgr*)cinfo->dest;
        dest->pub.init_destination = my_init_destination;
        dest->pub.empty_output_buffer = my_empty_output_buffer;
        dest->pub.term_destination = my_term_destination;
        dest->os = &os;
    }
    void writejpegimage(const std::string& file_name,const Image_& image){
        struct jpeg_compress_struct cinfo;
        struct jpeg_error_mgr       jerr;
        if (image.getChannel() != 1 && image.getChannel() != 3) {
            ERROR("Unsupported number of image channels.");
        }
        /*
        if (img->depth != IPL_DEPTH_8U) {
            ERROR("Unsupported image depth.");
        }
        */
        
        cinfo.err = jpeg_std_error(&jerr);
        jpeg_create_compress(&cinfo);
        std::ofstream ofs;
        ofs.open(file_name,std::ios::binary);
        if(!(ofs)){
            ERROR(file_name," couldn't open");
            abort();
        } 
        my_set_dest_mgr(&cinfo, ofs);
        
        cinfo.image_width      = image.getWidth();
        cinfo.image_height     = image.getHeight();
        cinfo.input_components = image.getChannel();
        if (image.getChannel() == 3) {
            cinfo.in_color_space   = JCS_RGB;
        }else {
            cinfo.in_color_space   = JCS_GRAYSCALE;
        }
        jpeg_set_defaults(&cinfo);
        jpeg_set_quality (&cinfo, 100, static_cast<boolean>(true)); // set max quality. [0..100]
        jpeg_start_compress(&cinfo, static_cast<boolean>(true));

        JSAMPROW row;
        while (cinfo.next_scanline < cinfo.image_height) {
            row = (JSAMPROW)((char*)image.getConstData().getConstData()+(cinfo.next_scanline*image.getConstData().getNumberofCols()));            
            jpeg_write_scanlines(&cinfo, &row, 1);
        }

        jpeg_finish_compress(&cinfo);
        jpeg_destroy_compress(&cinfo);
    }
}