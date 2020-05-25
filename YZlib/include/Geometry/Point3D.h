#ifndef YZ_POINT3D_HPP
#define YZ_POINT3D_HPP
#include <iostream>
#include "Geometry/Point2D.h"
namespace YZlib{
    template<typename Tp>
    class Point3D : public Point2D<Tp>
    {
    public:
        Tp z;
        Point3D();
        Point3D(const Tp&,const Tp&,const Tp&);
        Point3D(const Point3D&)noexcept;
        Point3D(Point3D&&)noexcept;

        Point3D& operator = (const Point3D&)noexcept;
        Point3D& operator = (Point3D&&)noexcept;

        Point3D  operator -()const;
        Point3D& operator +=(const Point3D&);
        Point3D& operator -=(const Point3D&);
        Point3D& operator *=(const Point3D&);
        Point3D& operator /=(const Point3D&);
        Point3D& operator %=(const Point3D&);
        Point3D& operator ^=(const Point3D&);
        
        Point3D operator +(const Point3D&)const;
        Point3D operator -(const Point3D&)const;
        Point3D operator *(const Point3D&)const;
        Point3D operator /(const Point3D&)const;
        Point3D operator %(const Point3D&)const;
        Point3D operator ^(const Point3D&)const;

        bool operator ==(const Point3D&)const;
        bool operator !=(const Point3D&)const;
        bool operator >=(const Point3D&)const;
        bool operator <=(const Point3D&)const;
        bool operator >(const Point3D&)const;
        bool operator <(const Point3D&)const;

        Tp sum()const;
        Tp mean()const;
        Tp distance()const;
        Point2D<Tp> to2D()const;
        ~Point3D();
    };
}
#include "Geometry/Point/Point3D_Impl.hpp"
#include "Geometry/Point/Point2D_Operators.hpp"
#endif