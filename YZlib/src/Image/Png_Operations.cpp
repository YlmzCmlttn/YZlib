#include "Image/Png_Operations.h"
#include "Core/Debug.hpp"
#include <fstream>
#include <png.h>
namespace YZlib{
    static void user_read_png_data(png_structp png_ptr, png_bytep data, png_size_t length) {
        std::istream *from = reinterpret_cast< std::istream * >(png_get_io_ptr(png_ptr));
        assert(from);
        if (!from->read(reinterpret_cast< char * >(data), length)) {
            png_error(png_ptr, "Error reading.");
        }
    }
    static void user_write_data(png_structp png_ptr, png_bytep data, png_size_t length) {
        std::ostream *to = reinterpret_cast< std::ostream * >(png_get_io_ptr(png_ptr));
        assert(to);
        if (!to->write(reinterpret_cast< char * >(data), length)) {
            png_error(png_ptr, "Error writing.");
        }
    }
    static void user_flush_data(png_structp png_ptr) {
        std::ostream *to = reinterpret_cast< std::ostream * >(png_get_io_ptr(png_ptr));
        assert(to);
        if (!to->flush()) {
            png_error(png_ptr, "Error flushing.");
        }
    }
    Image_ readpngimage(const std::string& file_name){
        std::ifstream ifs;
        ifs.open(file_name,std::ios::binary);
        if(!(ifs)){
            ERROR(file_name," couldn't open");
        }
        png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
        png_set_read_fn(png_ptr,&ifs,user_read_png_data);
        if(!png_ptr){
            ERROR("png_create_read_struct failed");
            ifs.close();
            abort();
        }
        png_infop info_ptr = png_create_info_struct(png_ptr);
        if(!info_ptr){
            ERROR("png_create_info_struct failed");
            png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
            ifs.close();
            abort();
        }        
        if (setjmp(png_jmpbuf(png_ptr))) {
            ERROR("png interal error.");
            png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
            ifs.close();
            abort();
        }
        png_read_info(png_ptr, info_ptr);
        unsigned int w = png_get_image_width(png_ptr, info_ptr);
        unsigned int h = png_get_image_height(png_ptr, info_ptr);
        Color_Type colorType;
        if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE){
            png_set_palette_to_rgb(png_ptr);
            colorType=Color_Type::RGB;
        }   
        if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY){
            colorType=Color_Type::GRAY;
        }
        if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA){
            colorType=Color_Type::GRAYA;
        }
        if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB){
            colorType=Color_Type::RGB;            
        }
        if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGBA){
            colorType=Color_Type::RGBA;            
        }
        if (png_get_bit_depth(png_ptr, info_ptr) < 8)
            png_set_packing(png_ptr);
        if (png_get_bit_depth(png_ptr,info_ptr) == 16)
            png_set_strip_16(png_ptr);
        png_read_update_info(png_ptr, info_ptr);
        //png_byte bit_depth = png_get_bit_depth(png_ptr, info_ptr);
        Matrix_<unsigned char> data(h,png_get_rowbytes(png_ptr,info_ptr));
        unsigned char** row_pointers = new png_bytep[h];
        for (unsigned int r = 0; r < h; ++r) {
                row_pointers[r] = new png_byte[png_get_rowbytes(png_ptr,info_ptr)];
        }
        png_read_image(png_ptr,row_pointers);
        for (unsigned int i = 0; i < h; i++) {
            for (unsigned int j = 0; j < png_get_rowbytes(png_ptr,info_ptr); j++) {
                data(i,j)=row_pointers[i][j];
            }
        }       
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        ifs.close();
        for (unsigned int r = 0; r < h; ++r) {
            delete[] row_pointers[r];
        }
        delete[] row_pointers;
        return Image_((size_t)w,(size_t)h,colorType,std::move(data));
    }
    void writepngimage(const std::string& file_name,const Image_& image){
        std::ofstream ofs;
        ofs.open(file_name,std::ios::binary);
        png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

	    png_set_write_fn(png_ptr, &ofs, user_write_data, user_flush_data);
        if (png_ptr == NULL) {
	    	ERROR("Can't create write struct.");
            ofs.close();
            abort();
        }
        png_infop info_ptr = png_create_info_struct(png_ptr);
        if (info_ptr == NULL) {
            png_destroy_write_struct(&png_ptr, NULL);
            ERROR("Can't craete info pointer");
            ofs.close();
            abort();
        }
        if (setjmp(png_jmpbuf(png_ptr))) {
            png_destroy_write_struct(&png_ptr, &info_ptr);
            ERROR("Error writing png.");
            ofs.close();
            abort();
        }
        auto type = PNG_COLOR_TYPE_RGBA;
        if(image.getColorType()==Color_Type::GRAY){
            type = PNG_COLOR_TYPE_GRAY;
        }else if(image.getColorType()==Color_Type::GRAYA){
            type = PNG_COLOR_TYPE_GRAY_ALPHA;
        }else if(image.getColorType()==Color_Type::RGB){
            type = PNG_COLOR_TYPE_RGB;            
        }else if(image.getColorType()==Color_Type::RGBA){
            type = PNG_COLOR_TYPE_RGBA;
        }
        png_set_IHDR(
            png_ptr,
            info_ptr,
            image.getWidth(), image.getHeight(),
            8,
            type,
            PNG_INTERLACE_NONE,
            PNG_COMPRESSION_TYPE_DEFAULT,
            PNG_FILTER_TYPE_DEFAULT
        );
        png_write_info(png_ptr, info_ptr);
        unsigned char** row_pointers = new png_bytep[image.getHeight()];
        for (unsigned int r = 0; r < image.getHeight(); ++r) {
                row_pointers[r] = new png_byte[png_get_rowbytes(png_ptr,info_ptr)];
        }
        for (unsigned int i = 0; i < image.getHeight(); i++) {
            for (unsigned int j = 0; j < png_get_rowbytes(png_ptr,info_ptr); j++) {
                row_pointers[i][j]=image.getConstData().get(i,j);
            }
        }        
        png_write_image(png_ptr, row_pointers);
        png_write_end(png_ptr, info_ptr);
        png_destroy_write_struct(&png_ptr, &info_ptr);
        for (unsigned int r = 0; r < image.getHeight(); ++r) {
            delete[] row_pointers[r];
        }
        delete[] row_pointers;
    }
}