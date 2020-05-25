#ifndef YZ_POINT2D_METHODS_HPP
#define YZ_POINT2D_METHODS_HPP
#include <iostream>
#include "Geometry/Point2D.h"
namespace YZlib{
    template<typename Tp>
    Tp Point2D<Tp>::sum()const{
        return (this->x+this->y);
    }
    template<typename Tp>
    Tp Point2D<Tp>::mean()const{
        return (this->x+this->y)/2;
    }
    template<typename Tp>
    Tp Point2D<Tp>::distance()const{
        return sqrt(pow(this->x,2)+pow(this->y,2));
    }
    template<typename Tp>
    Point3D<Tp> Point2D<Tp>::to3D(const Tp& z)const{
        return Point2D<Tp>(this->x,this->y);
    }
}
#endif