#ifndef YZ_BMP_OPERATIONS_H
#define YZ_BMP_OPERATIONS_H
#include <iostream>
#include "Image/Image.h"
namespace YZlib{
    Image_ readbmpimage(const std::string&);
    void writebmpimage(const std::string&,const Image_&);
}
#endif