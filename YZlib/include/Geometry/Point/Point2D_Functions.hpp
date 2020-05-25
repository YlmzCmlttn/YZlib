#ifndef YZ_POINT2D_FUNCTIONS_HPP
#define YZ_POINT2D_FUNCTIONS_HPP
#include <iostream>
#include "Geometry/Point2D.h"
namespace YZlib{
    template <typename Tp>
    Point2D<Tp> cos(const Point2D<Tp>& p){
        return Point2D<Tp>(::cos(p.x),::cos(p.y));
    }
    template <typename Tp>
    Point2D<Tp> sin(const Point2D<Tp>& p){
        return Point2D<Tp>(::sin(p.x),::sin(p.y));
    }
    template <typename Tp>
    Point2D<Tp> tan(const Point2D<Tp>& p){
        return Point2D<Tp>(::tan(p.x),::tan(p.y));
    }
    template <typename Tp>
    Point2D<Tp> acos(const Point2D<Tp>& p){
        return Point2D<Tp>(::acos(p.x),::acos(p.y));
    }
    template <typename Tp>
    Point2D<Tp> asin(const Point2D<Tp>& p){
        return Point2D<Tp>(::asin(p.x),::asin(p.y));
    }
    template <typename Tp>
    Point2D<Tp> atan(const Point2D<Tp>& p){
        return Point2D<Tp>(::atan(p.x),::atan(p.y));
    }
    template <typename Tp>
    Point2D<Tp> atan2(const Point2D<Tp>& p){
        return Point2D<Tp>(::atan2(p.x),::atan2(p.y));
    }
    template <typename Tp>
    Point2D<Tp> cosh(const Point2D<Tp>& p){
        return Point2D<Tp>(::cosh(p.x),::cosh(p.y));
    }
    template <typename Tp>
    Point2D<Tp> sinh(const Point2D<Tp>& p){
        return Point2D<Tp>(::sinh(p.x),::sinh(p.y));
    }
    template <typename Tp>
    Point2D<Tp> tanh(const Point2D<Tp>& p){
        return Point2D<Tp>(::tanh(p.x),::tanh(p.y));
    }
    template <typename Tp>
    Point2D<Tp> acosh(const Point2D<Tp>& p){
        return Point2D<Tp>(::acosh(p.x),::acosh(p.y));
    }
    template <typename Tp>
    Point2D<Tp> asinh(const Point2D<Tp>& p){
        return Point2D<Tp>(::asinh(p.x),::asinh(p.y));
    }
    template <typename Tp>
    Point2D<Tp> atanh(const Point2D<Tp>& p){
        return Point2D<Tp>(::atanh(p.x),::atanh(p.y));
    }
    template <typename Tp>
    Point2D<Tp> exp(const Point2D<Tp>& p){
        return Point2D<Tp>(::exp(p.x),::exp(p.y));
    }
    template <typename Tp>
    Point2D<Tp> log(const Point2D<Tp>& p){
        return Point2D<Tp>(::log(p.x),::log(p.y));
    }
    template <typename Tp>
    Point2D<Tp> log10(const Point2D<Tp>& p){
        return Point2D<Tp>(::log10(p.x),::log10(p.y));
    }
    template <typename Tp>
    Point2D<Tp> pow(const Point2D<Tp>& p,const Point2D<Tp>& p2){
        return Point2D<Tp>(::pow(p.x,p2.x),::pow(p.y,p2.y));
    }
    template <typename Tp>
    Point2D<Tp> pow(const Point2D<Tp>& p,const Tp& p2){
        return Point2D<Tp>(::pow(p.x,p2),::pow(p.y,p2));
    }
    template <typename Tp>
    Point2D<Tp> sqrt(const Point2D<Tp>& p,const Point2D<Tp>& p2){
        return Point2D<Tp>(::sqrt(p.x,p2.x),::sqrt(p.y,p2.y));
    }
    template <typename Tp>
    Point2D<Tp> sqrt(const Point2D<Tp>& p,const Tp& p2){
        return Point2D<Tp>(::sqrt(p.x,p2),::sqrt(p.y,p2));
    }
    template <typename Tp>
    Point2D<Tp> hypot(const Point2D<Tp>& p,const Point2D<Tp>& p2){
        return Point2D<Tp>(::hypot(p.x,p2.x),::hypot(p.y,p2.y));
    }
    template <typename Tp>
    Point2D<Tp> hypot(const Point2D<Tp>& p,const Tp& p2){
        return Point2D<Tp>(::hypot(p.x,p2),::hypot(p.y,p2));
    }
    template <typename Tp>
    Point2D<Tp> ceil(const Point2D<Tp>& p){
        return Point2D<Tp>(::ceil(p.x),::ceil(p.y));
    }
    template <typename Tp>
    Point2D<Tp> floor(const Point2D<Tp>& p){
        return Point2D<Tp>(::floor(p.x),::floor(p.y));
    }
    template <typename Tp>
    Point2D<Tp> round(const Point2D<Tp>& p){
        return Point2D<Tp>(::round(p.x),::round(p.y));
    }
    template <typename Tp>
    Point2D<Tp> fmod(const Point2D<Tp>& p,const Point2D<Tp>& p2){
        return Point2D<Tp>(::fmod(p.x,p2.x),::fmod(p.y,p2.y));
    }
    template <typename Tp>
    Point2D<Tp> fmod(const Point2D<Tp>& p,const Tp& p2){
        return Point2D<Tp>(::fmod(p.x,p2),::fmod(p.y,p2));
    }
    template <typename Tp>
    Point2D<Tp> trunc(const Point2D<Tp>& p){
        return Point2D<Tp>(::trunc(p.x),::trunc(p.y));
    }
    template <typename Tp>
    Point2D<Tp> abs(const Point2D<Tp>& p){
        return Point2D<Tp>(::abs(p.x),::abs(p.y));
    }
}
#endif