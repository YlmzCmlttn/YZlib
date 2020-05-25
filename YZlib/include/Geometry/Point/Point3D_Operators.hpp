#ifndef YZ_POINT3D_OPERATORS_HPP
#define YZ_POINT3D_OPERATORS_HPP
#include <iostream>
#include "Geometry/Point3D.h"
namespace YZlib{
    template<typename Tp>
    Point3D<Tp>  Point3D<Tp>::operator -()const{
        return Point3D<Tp>(-1*this->x,-1*this->y,-1*this->z);
    }
    template<typename Tp>
    Point3D<Tp>& Point3D<Tp>::operator +=(const Point3D<Tp>& _p){
        this->x+=_p.x;
        this->y+=_p.y;
        this->z+=_p.z;
        return *this;
    }
    template<typename Tp>
    Point3D<Tp>& Point3D<Tp>::operator -=(const Point3D<Tp>& _p){
        this->x-=_p.x;
        this->y-=_p.y;
        this->z-=_p.z;
        return *this;
    }
    template<typename Tp>
    Point3D<Tp>& Point3D<Tp>::operator *=(const Point3D<Tp>& _p){
        this->x*=_p.x;
        this->y*=_p.y;
        this->z*=_p.z;
        return *this;
    }
    template<typename Tp>
    Point3D<Tp>& Point3D<Tp>::operator /=(const Point3D<Tp>& _p){
        this->x/=_p.x;
        this->y/=_p.y;
        this->z/=_p.z;
        return *this;
    }
    template<typename Tp>
    Point3D<Tp>& Point3D<Tp>::operator %=(const Point3D<Tp>& _p){
        this->x%=_p.x;
        this->y%=_p.y;
        this->z%=_p.z;
        return *this;
    }
    template<typename Tp>
    Point3D<Tp>& Point3D<Tp>::operator ^=(const Point3D<Tp>& _p){
        this->x^=_p.x;
        this->y^=_p.y;
        this->z^=_p.z;
        return *this;
    }
    template<typename Tp>
    Point3D<Tp> Point3D<Tp>::operator +(const Point3D<Tp>& _p)const{
        return Point3D<Tp>(*this)+=_p;
    }
    template<typename Tp>
    Point3D<Tp> Point3D<Tp>::operator -(const Point3D<Tp>& _p)const{
        return Point3D<Tp>(*this)-=_p;
    }
    template<typename Tp>
    Point3D<Tp> Point3D<Tp>::operator *(const Point3D<Tp>& _p)const{
        return Point3D<Tp>(*this)*=_p;
    }
    template<typename Tp>
    Point3D<Tp> Point3D<Tp>::operator /(const Point3D<Tp>& _p)const{
        return Point3D<Tp>(*this)/=_p;
    }
    template<typename Tp>
    Point3D<Tp> Point3D<Tp>::operator %(const Point3D<Tp>& _p)const{
        return Point3D<Tp>(*this)%=_p;
    }
    template<typename Tp>
    Point3D<Tp> Point3D<Tp>::operator ^(const Point3D<Tp>& _p)const{
        return Point3D<Tp>(*this)^=_p;
    }
    template<typename Tp>
    bool Point3D<Tp>::operator ==(const Point3D<Tp>& _p)const{
        return bool((this->x==_p.x)&&(this->y==_p.y)&&(this->z==_p.z));
    }
    template<typename Tp>
    bool Point3D<Tp>::operator !=(const Point3D<Tp>& _p)const{
        return bool((this->x!=_p.x)||(this->y!=_p.y)||(this->z!=_p.z));
    }
    template<typename Tp>
    bool Point3D<Tp>::operator >=(const Point3D<Tp>& _p)const{
        return bool((this->x>=_p.x)&&(this->y>=_p.y)&&(this->z>=_p.z));
    }
    template<typename Tp>
    bool Point3D<Tp>::operator <=(const Point3D<Tp>& _p)const{
        return bool((this->x<=_p.x)&&(this->y<=_p.y)&&(this->z<=_p.z));
    }
    template<typename Tp>
    bool Point3D<Tp>::operator >(const Point3D<Tp>& _p)const{
        return bool((this->x>_p.x)&&(this->y>_p.y)&&(this->z>_p.z));
    }
    template<typename Tp>
    bool Point3D<Tp>::operator <(const Point3D<Tp>& _p)const{
        return bool((this->x<_p.x)&&(this->y<_p.y)&&(this->z<_p.z));
    }
}
#endif