#ifndef YZ_POINT3D_FUNCTIONS_HPP
#define YZ_POINT3D_FUNCTIONS_HPP
#include <iostream>
#include "Geometry/Point3D.h"
namespace YZlib{
    template <typename Tp>
    Point3D<Tp> cos(const Point3D<Tp>& p){
        return Point3D<Tp>(::cos(p.x),::cos(p.y),::cos(p.z));
    }
    template <typename Tp>
    Point3D<Tp> sin(const Point3D<Tp>& p){
        return Point3D<Tp>(::sin(p.x),::sin(p.y),::sin(p.z));
    }
    template <typename Tp>
    Point3D<Tp> tan(const Point3D<Tp>& p){
        return Point3D<Tp>(::tan(p.x),::tan(p.y),::tan(p.z));
    }
    template <typename Tp>
    Point3D<Tp> acos(const Point3D<Tp>& p){
        return Point3D<Tp>(::acos(p.x),::acos(p.y),::acos(p.z));
    }
    template <typename Tp>
    Point3D<Tp> asin(const Point3D<Tp>& p){
        return Point3D<Tp>(::asin(p.x),::asin(p.y),::asin(p.z));
    }
    template <typename Tp>
    Point3D<Tp> atan(const Point3D<Tp>& p){
        return Point3D<Tp>(::atan(p.x),::atan(p.y),::atan(p.z));
    }
    template <typename Tp>
    Point3D<Tp> atan2(const Point3D<Tp>& p){
        return Point3D<Tp>(::atan2(p.x),::atan2(p.y),::atan2(p.z));
    }
    template <typename Tp>
    Point3D<Tp> cosh(const Point3D<Tp>& p){
        return Point3D<Tp>(::cosh(p.x),::cosh(p.y),::cosh(p.z));
    }
    template <typename Tp>
    Point3D<Tp> sinh(const Point3D<Tp>& p){
        return Point3D<Tp>(::sinh(p.x),::sinh(p.y),::sinh(p.z));
    }
    template <typename Tp>
    Point3D<Tp> tanh(const Point3D<Tp>& p){
        return Point3D<Tp>(::tanh(p.x),::tanh(p.y),::tanh(p.z));
    }
    template <typename Tp>
    Point3D<Tp> acosh(const Point3D<Tp>& p){
        return Point3D<Tp>(::acosh(p.x),::acosh(p.y),::acosh(p.z));
    }
    template <typename Tp>
    Point3D<Tp> asinh(const Point3D<Tp>& p){
        return Point3D<Tp>(::asinh(p.x),::asinh(p.y),::asinh(p.z));
    }
    template <typename Tp>
    Point3D<Tp> atanh(const Point3D<Tp>& p){
        return Point3D<Tp>(::atanh(p.x),::atanh(p.y),::atanh(p.z));
    }
    template <typename Tp>
    Point3D<Tp> exp(const Point3D<Tp>& p){
        return Point3D<Tp>(::exp(p.x),::exp(p.y),::exp(p.z));
    }
    template <typename Tp>
    Point3D<Tp> log(const Point3D<Tp>& p){
        return Point3D<Tp>(::log(p.x),::log(p.y),::log(p.z));
    }
    template <typename Tp>
    Point3D<Tp> log10(const Point3D<Tp>& p){
        return Point3D<Tp>(::log10(p.x),::log10(p.y),::log10(p.z));
    }
    template <typename Tp>
    Point3D<Tp> pow(const Point3D<Tp>& p,const Point3D<Tp>& p2){
        return Point3D<Tp>(::pow(p.x,p2.x),::pow(p.y,p2.y),::pow(p.z,p2.y));
    }
    template <typename Tp>
    Point3D<Tp> pow(const Point3D<Tp>& p,const Tp& p2){
        return Point3D<Tp>(::pow(p.x,p2),::pow(p.y,p2),::pow(p.z,p2));
    }
    template <typename Tp>
    Point3D<Tp> sqrt(const Point3D<Tp>& p,const Point3D<Tp>& p2){
        return Point3D<Tp>(::sqrt(p.x,p2.x),::sqrt(p.y,p2.y),::sqrt(p.z,p2.y));
    }
    template <typename Tp>
    Point3D<Tp> sqrt(const Point3D<Tp>& p,const Tp& p2){
        return Point3D<Tp>(::sqrt(p.x,p2),::sqrt(p.y,p2),::sqrt(p.z,p2));
    }
    template <typename Tp>
    Point3D<Tp> hypot(const Point3D<Tp>& p,const Point3D<Tp>& p2){
        return Point3D<Tp>(::hypot(p.x,p2.x),::hypot(p.y,p2.y),::hypot(p.z,p2.y));
    }
    template <typename Tp>
    Point3D<Tp> hypot(const Point3D<Tp>& p,const Tp& p2){
        return Point3D<Tp>(::hypot(p.x,p2),::hypot(p.y,p2),::hypot(p.z,p2));
    }
    template <typename Tp>
    Point3D<Tp> ceil(const Point3D<Tp>& p){
        return Point3D<Tp>(::ceil(p.x),::ceil(p.y),::ceil(p.z));
    }
    template <typename Tp>
    Point3D<Tp> floor(const Point3D<Tp>& p){
        return Point3D<Tp>(::floor(p.x),::floor(p.y),::floor(p.z));
    }
    template <typename Tp>
    Point3D<Tp> round(const Point3D<Tp>& p){
        return Point3D<Tp>(::round(p.x),::round(p.y),::round(p.z));
    }
    template <typename Tp>
    Point3D<Tp> fmod(const Point3D<Tp>& p,const Point3D<Tp>& p2){
        return Point3D<Tp>(::fmod(p.x,p2.x),::fmod(p.y,p2.y),::fmod(p.z,p2.y));
    }
    template <typename Tp>
    Point3D<Tp> fmod(const Point3D<Tp>& p,const Tp& p2){
        return Point3D<Tp>(::fmod(p.x,p2),::fmod(p.y,p2),::fmod(p.z,p2));
    }
    template <typename Tp>
    Point3D<Tp> trunc(const Point3D<Tp>& p){
        return Point3D<Tp>(::trunc(p.x),::trunc(p.y),::trunc(p.z));
    }
    template <typename Tp>
    Point3D<Tp> abs(const Point3D<Tp>& p){
        return Point3D<Tp>(::abs(p.x),::abs(p.y),::trunc(p.z));
    }
}
#endif