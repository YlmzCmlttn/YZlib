#ifndef YZ_JPEG_OPERATIONS_H
#define YZ_JPEG_OPERATIONS_H
#include <iostream>
#include "Image/Image.h"
namespace YZlib{
    Image_ readjpegimage(const std::string&);
    void writejpegimage(const std::string&,const Image_&);
}
#endif