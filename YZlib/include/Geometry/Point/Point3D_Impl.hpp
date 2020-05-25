#ifndef YZ_POINT3D_IMPL_HPP
#define YZ_POINT3D_IMPL_HPP
#include "Geometry/Point3D.h"
namespace YZlib{    
    template<typename Tp>
    Point3D<Tp>::Point3D(/* args */):Point2D<Tp>(),z(0){
        POINT_INFO_D("Point3D()");
    }
    template<typename Tp>
    Point3D<Tp>::Point3D(const Tp& _x,const Tp& _y,const Tp& _z):Point2D<Tp>(_x,_y),z(_z){
        POINT_INFO_D("Point3D(Tp ",_x,",Tp ",_y,"Tp ",_z,")");
    }
    template<typename Tp>
    Point3D<Tp>::Point3D(const Point3D& _p)noexcept:Point2D<Tp>(_x,_y),z(_z){
        POINT_INFO_D("Point3D(const Point3D& _p)");
    }
    template<typename Tp>
    Point3D<Tp>::Point3D(Point3D&& _p)noexcept:Point2D<Tp>(_x,_y),z(_z){
        POINT_INFO_D("Point3D(Point3D&& _p)");
    }
    template<typename Tp>
    Point3D<Tp>::~Point3D(){
        POINT_INFO_D("~Point3D()");
    }
}
#endif