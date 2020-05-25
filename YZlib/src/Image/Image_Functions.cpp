#include "Image/Image_Functions.h"
#include "Image/Png_Operations.h"
#include "Image/Jpeg_Operations.h"
#include "Image/Bmp_Operations.h"
namespace YZlib{
    Image_Type getImageExtenstion(const std::string& filename){
        int i;
        for(i=filename.size();i>=0;i--){
            if(filename[i]=='.'){
                break;
            }
        }
        std::string n = filename.substr(i+1,filename.size());
        if(n=="png"){
            return Image_Type::PNG;
        }else if(n=="jpg" || n=="jpeg"){
            return Image_Type::JPG;
        }else if(n=="bmp"){
            return Image_Type::BMP;
        }else{
            ERROR(n," is unknown data type");
            abort();
        }
    }
    Image_ imread(const std::string& filename){
        Image_Type type = getImageExtenstion(filename);
        if(type==Image_Type::PNG){
            return readpngimage(filename);
        }else if(type==Image_Type::JPG){
            return readjpegimage(filename);
        }else if(type==Image_Type::BMP){
            return readbmpimage(filename);
        }else{
            abort();
        }
    }
    void imwrite(const std::string& filename,const Image_& image){
        Image_Type type = getImageExtenstion(filename);
        if(type==Image_Type::PNG){
            writepngimage(filename,image);
        }else if(type==Image_Type::JPG){
            writejpegimage(filename,image);
        }else if(type==Image_Type::BMP){
            writebmpimage(filename,image);
        }
    }
}