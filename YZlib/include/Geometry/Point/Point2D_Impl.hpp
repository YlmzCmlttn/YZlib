#ifndef YZ_POINT2D_IMPL_HPP
#define YZ_POINT2D_IMPL_HPP
#include "Geometry/Point2D.h"
namespace YZlib{
    template<typename Tp>
    Point2D<Tp>::Point2D():x(0),y(0){
        POINT_INFO_D("Point2D()");
    }
    template<typename Tp>
    Point2D<Tp>::Point2D(const Tp& _x,const Tp& _y):x(_x),y(_y){
        POINT_INFO_D("Point2D(Tp ",_x,",Tp ",_y,")");
    }
    template<typename Tp>
    Point2D<Tp>::Point2D(const Point2D& _p)noexcept:x(_p.x),y(_p.y){
        POINT_INFO_D("Point2D(const Point2D& _p)");
    }
    template<typename Tp>
    Point2D<Tp>::Point2D(Point2D&& _p)noexcept:x(std::move(_p.x)),y(std::move(_p.y)){
        POINT_INFO_D("Point2D(Point2D&& _p)");
    }
    template<typename Tp>
    Point2D<Tp>::~Point2D(){
        POINT_INFO_D("~Point2D()");
    }
}
#endif