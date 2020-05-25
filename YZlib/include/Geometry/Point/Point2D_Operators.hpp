#ifndef YZ_POINT2D_OPERATORS_HPP
#define YZ_POINT2D_OPERATORS_HPP
#include <iostream>
#include "Geometry/Point2D.h"
namespace YZlib{
    template<typename Tp>
    Point2D<Tp>  Point2D<Tp>::operator -()const{
        return Point2D<Tp>(-1*this->x,-1*this->y);
    }
    template<typename Tp>
    Point2D<Tp>& Point2D<Tp>::operator +=(const Point2D<Tp>& _p){
        this->x+=_p.x;
        this->y+=_p.y;
        return *this;
    }
    template<typename Tp>
    Point2D<Tp>& Point2D<Tp>::operator -=(const Point2D<Tp>& _p){
        this->x-=_p.x;
        this->y-=_p.y;
        return *this;
    }
    template<typename Tp>
    Point2D<Tp>& Point2D<Tp>::operator *=(const Point2D<Tp>& _p){
        this->x*=_p.x;
        this->y*=_p.y;
        return *this;
    }
    template<typename Tp>
    Point2D<Tp>& Point2D<Tp>::operator /=(const Point2D<Tp>& _p){
        this->x/=_p.x;
        this->y/=_p.y;
        return *this;
    }
    template<typename Tp>
    Point2D<Tp>& Point2D<Tp>::operator %=(const Point2D<Tp>& _p){
        this->x%=_p.x;
        this->y%=_p.y;
        return *this;
    }
    template<typename Tp>
    Point2D<Tp>& Point2D<Tp>::operator ^=(const Point2D<Tp>& _p){
        this->x^=_p.x;
        this->y^=_p.y;
        return *this;
    }
    template<typename Tp>
    Point2D<Tp> Point2D<Tp>::operator +(const Point2D<Tp>& _p)const{
        return Point2D<Tp>(*this)+=_p;
    }
    template<typename Tp>
    Point2D<Tp> Point2D<Tp>::operator -(const Point2D<Tp>& _p)const{
        return Point2D<Tp>(*this)-=_p;
    }
    template<typename Tp>
    Point2D<Tp> Point2D<Tp>::operator *(const Point2D<Tp>& _p)const{
        return Point2D<Tp>(*this)*=_p;
    }
    template<typename Tp>
    Point2D<Tp> Point2D<Tp>::operator /(const Point2D<Tp>& _p)const{
        return Point2D<Tp>(*this)/=_p;
    }
    template<typename Tp>
    Point2D<Tp> Point2D<Tp>::operator %(const Point2D<Tp>& _p)const{
        return Point2D<Tp>(*this)%=_p;
    }
    template<typename Tp>
    Point2D<Tp> Point2D<Tp>::operator ^(const Point2D<Tp>& _p)const{
        return Point2D<Tp>(*this)^=_p;
    }
    template<typename Tp>
    bool Point2D<Tp>::operator ==(const Point2D<Tp>& _p)const{
        return bool(this->x==_p.x)&&(this->y==_p.y);
    }
    template<typename Tp>
    bool Point2D<Tp>::operator !=(const Point2D<Tp>& _p)const{
        return bool(this->x!=_p.x)||(this->y!=_p.y);
    }
    template<typename Tp>
    bool Point2D<Tp>::operator >=(const Point2D<Tp>& _p)const{
        return bool(this->x>=_p.x)&&(this->y>=_p.y);
    }
    template<typename Tp>
    bool Point2D<Tp>::operator <=(const Point2D<Tp>& _p)const{
        return bool(this->x<=_p.x)&&(this->y<=_p.y);
    }
    template<typename Tp>
    bool Point2D<Tp>::operator >(const Point2D<Tp>& _p)const{
        return bool(this->x>_p.x)&&(this->y>_p.y);
    }
    template<typename Tp>
    bool Point2D<Tp>::operator <(const Point2D<Tp>& _p)const{
        return bool(this->x<_p.x)&&(this->y<_p.y);
    }
}
#endif