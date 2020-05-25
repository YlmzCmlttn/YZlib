#ifndef YZ_IMAGE_FUNCTIONS_H
#define YZ_IMAGE_FUNCTIONS_H
#include "Image/Image.h"
#include "Image/Image_.h"
namespace YZlib{
    Image_Type getImageExtenstion(const std::string&);
    Image_ imread(const std::string&);
    void imwrite(const std::string&,const Image_&);
}
#endif