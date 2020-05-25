#ifndef YZ_POINT2D_HPP
#define YZ_POINT2D_HPP
#include <iostream>
#include "Geometry/Point3D.h"
namespace YZlib{
    template<typename Tp>
    class Point2D
    {
    public:
        Tp x;
        Tp y;

        Point2D();
        Point2D(const Tp&,const Tp&);

        Point2D(const Point2D&)noexcept;
        Point2D(Point2D&&)noexcept;

        Point2D& operator = (const Point2D&)noexcept;
        Point2D& operator = (Point2D&&)noexcept;

        Point2D  operator -()const;
        Point2D& operator +=(const Point2D&);
        Point2D& operator -=(const Point2D&);
        Point2D& operator *=(const Point2D&);
        Point2D& operator /=(const Point2D&);
        Point2D& operator %=(const Point2D&);
        Point2D& operator ^=(const Point2D&);
        
        Point2D operator +(const Point2D&)const;
        Point2D operator -(const Point2D&)const;
        Point2D operator *(const Point2D&)const;
        Point2D operator /(const Point2D&)const;
        Point2D operator %(const Point2D&)const;
        Point2D operator ^(const Point2D&)const;

        bool operator ==(const Point2D&)const;
        bool operator !=(const Point2D&)const;
        bool operator >=(const Point2D&)const;
        bool operator <=(const Point2D&)const;
        bool operator >(const Point2D&)const;
        bool operator <(const Point2D&)const;
        
        Tp sum()const;
        Tp mean()const;
        Tp distance()const;
        Point3D<Tp> to3D(const Tp&)const;
        ~Point2D();
    };
}
#include "Geometry/Point/Point2D_Impl.hpp"
#include "Geometry/Point/Point2D_Operators.hpp"
#endif