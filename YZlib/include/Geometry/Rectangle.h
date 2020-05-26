#ifndef YZ_RECTANGLE_H
#define YZ_RECTANGLE_H
#include <iostream>
#include <utility>
#include "Geometry/Point2D.h"
namespace YZlib{
    template<typename Tp>
    class Rectangle
    {    
    public:
        Tp x;
        Tp y;
        Tp width;
        Tp height;
    public:
        Rectangle();
        Rectangle(const Rectangle&);
        Rectangle(Rectangle&&)noexcept;        
        Rectangle(const Point2D<Tp>&,const Point2D<Tp>&);//NOT IMPLEMENTED
        Rectangle(const Point2D<Tp>&,const Tp&,const Tp&);//NOT IMPLEMENTED
        Rectangle(const Tp&,const Tp&,const Tp&,const Tp&);
        //Operators
        Rectangle& operator = (const Rectangle&);
        Rectangle& operator = (Rectangle&&)noexcept;

        Rectangle  operator -()const;//NOT IMPLEMENTED
        Rectangle& operator +=(const Rectangle&);//NOT IMPLEMENTED
        Rectangle& operator -=(const Rectangle&);//NOT IMPLEMENTED
        Rectangle& operator *=(const Rectangle&);//NOT IMPLEMENTED
        Rectangle& operator /=(const Rectangle&);//NOT IMPLEMENTED
        Rectangle& operator %=(const Rectangle&);//NOT IMPLEMENTED
        Rectangle& operator ^=(const Rectangle&);//NOT IMPLEMENTED
        
        Rectangle operator +(const Rectangle&)const;//NOT IMPLEMENTED
        Rectangle operator -(const Rectangle&)const;//NOT IMPLEMENTED
        Rectangle operator *(const Rectangle&)const;//NOT IMPLEMENTED
        Rectangle operator /(const Rectangle&)const;//NOT IMPLEMENTED
        Rectangle operator %(const Rectangle&)const;//NOT IMPLEMENTED
        Rectangle operator ^(const Rectangle&)const;//NOT IMPLEMENTED

        bool operator ==(const Rectangle&)const;//NOT IMPLEMENTED
        bool operator !=(const Rectangle&)const;//NOT IMPLEMENTED
        bool operator >=(const Rectangle&)const;//NOT IMPLEMENTED
        bool operator <=(const Rectangle&)const;//NOT IMPLEMENTED
        bool operator >(const Rectangle&)const;//NOT IMPLEMENTED
        bool operator <(const Rectangle&)const;//NOT IMPLEMENTED
        
        //Methods
        Tp getX();//NOT IMPLEMENTED        
        Tp getY();        //NOT IMPLEMENTED
        Tp getWidth();//NOT IMPLEMENTED
        Tp getHeight();//NOT IMPLEMENTED

        void setX(const Tp&);//NOT IMPLEMENTED
        void setY(const Tp&);//NOT IMPLEMENTED
        void setWidth(const Tp&);//NOT IMPLEMENTED
        void setHeight(const Tp&);//NOT IMPLEMENTED

        Point2D<Tp> getTopLeft();//NOT IMPLEMENTED        
        Point2D<Tp> getTopRight();//NOT IMPLEMENTED
        Point2D<Tp> getBottomLeft();//NOT IMPLEMENTED
        Point2D<Tp> getBottomRight();//NOT IMPLEMENTED

        void setTopLeft(const Point2D<Tp>&);//NOT IMPLEMENTED
        void setTopRight(const Point2D<Tp>&);//NOT IMPLEMENTED
        void setBottomLeft(const Point2D<Tp>&);//NOT IMPLEMENTED
        void setBottomRight(const Point2D<Tp>&);//NOT IMPLEMENTED

        Tp area();//NOT IMPLEMENTED
        Point2D<double> center();//NOT IMPLEMENTED

        ~Rectangle();
    };
}
#include "Geometry/Rectangle/Rectangle_Impl.hpp"
#endif