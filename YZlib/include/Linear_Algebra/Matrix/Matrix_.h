#ifndef YZ_MATRIX__HPP
#define YZ_MATRIX__HPP
#include <iostream>
#include "Core/Size.h"
namespace YZlib{
    enum class Major_Order{
            Row_Major=0,
            Col_Major=1
    };
    enum class Parallel{
            Single=0,
            Parallel=1
    };
    uint from2Dto1D(const uint& row,const uint& col,
                    const Size& s,
                    const Major_Order& raw_majored=Major_Order::Row_Major);

    Size from1Dto2D(const uint& index,const Size& s,
                    const Major_Order& raw_majored=Major_Order::Row_Major);
    
}

#endif