#ifndef YZ_PNG_OPERATIONS_H
#define YZ_PNG_OPERATIONS_H
#include <iostream>
#include "Image/Image.h"
namespace YZlib{
    Image_ readpngimage(const std::string&);
    void writepngimage(const std::string&,const Image_&);
}
#endif