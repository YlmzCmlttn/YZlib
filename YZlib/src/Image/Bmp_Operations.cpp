#include "Image/Bmp_Operations.h"
#include "Image/Bmp_Struct.h"
#include "Core/Debug.hpp"
#include <fstream>
namespace YZlib{ 
    Image_ readbmpimage(const std::string& file_name){
        //TO BE IMPLEMENTED
        BMP bmp(file_name.c_str());
        auto width = bmp.bmp_info_header.width;
        auto height = bmp.bmp_info_header.height;
        auto channels = bmp.bmp_info_header.bit_count/8;
        std::cout<<width<<std::endl;
        std::cout<<height<<std::endl;
        Matrix_<unsigned char> data(height,channels*width);
        for(int x = 0;x<width;x++){
            for(int y = 0;y<height;y++){
                data(height-(y+1),3*x+2)=bmp.data[channels * (y * bmp.bmp_info_header.width + x) + 0];
                data(height-(y+1),3*x+1)=bmp.data[channels * (y * bmp.bmp_info_header.width + x) + 1];
                data(height-(y+1),3*x+0)=bmp.data[channels * (y * bmp.bmp_info_header.width + x) + 2];
                if (channels == 4) {
                    data(y,4*x+2)=bmp.data[channels * (y * bmp.bmp_info_header.width + x) + 0];
                    data(y,4*x+1)=bmp.data[channels * (y * bmp.bmp_info_header.width + x) + 1];
                    data(y,4*x+0)=bmp.data[channels * (y * bmp.bmp_info_header.width + x) + 2];
                    data(y,4*x+3)=bmp.data[channels * (y * bmp.bmp_info_header.width + x) + 3];
                }
            }
        }
        return Image_((size_t)width,(size_t)height,channels,std::move(data));
    }
    void writebmpimage(const std::string& file_name,const Image_& image){
        bool alpha;
        if(image.getChannel()==4){
            alpha = true;
        }else if(image.getChannel()==3){
            alpha = false;
        }else{
            ERROR("Not supported");
            abort();
        }
        BMP bmp(image.getWidth(),image.getHeight(),alpha);
        for(uint x = 0;x<image.getWidth();x++){
            for(uint y = 0;y<image.getHeight();y++){
                auto R = image.getConstData().get(y,3*x+0);
                auto G = image.getConstData().get(y,3*x+1);
                auto B = image.getConstData().get(y,3*x+2);
                auto A = 0;
                if(alpha){
                    R = image.getConstData().get(y,4*x+0);
                    G = image.getConstData().get(y,4*x+1);
                    B = image.getConstData().get(y,4*x+2);
                    A = image.getConstData().get(y,4*x+3);
                }
                bmp.set_pixel(x,image.getHeight()-(y+1),B,G,R,A);
            }
        }
        bmp.write(file_name.c_str());
    }
}