#ifndef YZ_POINT3D_METHODS_HPP
#define YZ_POINT3D_METHODS_HPP
#include <iostream>
#include "Geometry/Point3D.h"
namespace YZlib{
    template<typename Tp>
    Tp Point3D<Tp>::sum()const{
        return (this->x+this->y+this->z);
    }
    template<typename Tp>
    Tp Point3D<Tp>::mean()const{
        return (this->x+this->y+this->z)/3;
    }
    template<typename Tp>
    Tp Point3D<Tp>::distance()const{
        return sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
    }
    template<typename Tp>
    Point2D<Tp> Point3D<Tp>::to2D()const{
        return Point2D<Tp>(this->x,this->y);
    }
}
#endif