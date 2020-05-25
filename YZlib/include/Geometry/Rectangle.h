#ifndef YZ_RECTANGLE_H
#define YZ_RECTANGLE_H
#include <iostream>
#include <pair>
#include "Geometry/Point2D.h"
namespace YZlib{
    template<typename Tp>
    class Rectangle
    {
    private:
        std::pair<Point2D<Tp>> _points;
    public:
        Rectangle();
        Rectangle(const Rectangle&)noexcept;
        Rectangle(Rectangle&&)noexcept;
        Rectangle(const std::pair<Point2D<Tp>>&);
        Rectangle(const Point2D<Tp>&,const Point2D<Tp>&);
        Rectangle(const Point2D<Tp>&,const Tp&,const Tp&);
        Rectangle(const Tp&,const Tp&,const Tp&,const Tp&);
        //Operators
        Rectangle& operator = (const Rectangle&)noexcept;
        Rectangle& operator = (Rectangle&&)noexcept;

        Rectangle  operator -()const;
        Rectangle& operator +=(const Rectangle&);
        Rectangle& operator -=(const Rectangle&);
        Rectangle& operator *=(const Rectangle&);
        Rectangle& operator /=(const Rectangle&);
        Rectangle& operator %=(const Rectangle&);
        Rectangle& operator ^=(const Rectangle&);
        
        Rectangle operator +(const Rectangle&)const;
        Rectangle operator -(const Rectangle&)const;
        Rectangle operator *(const Rectangle&)const;
        Rectangle operator /(const Rectangle&)const;
        Rectangle operator %(const Rectangle&)const;
        Rectangle operator ^(const Rectangle&)const;

        bool operator ==(const Rectangle&)const;
        bool operator !=(const Rectangle&)const;
        bool operator >=(const Rectangle&)const;
        bool operator <=(const Rectangle&)const;
        bool operator >(const Rectangle&)const;
        bool operator <(const Rectangle&)const;
        
        //Methods
        Tp getX();        
        Tp getY();        
        Tp getWidth();
        Tp getHeight();

        void setX(const Tp&);
        void setY(const Tp&);
        void setWidth(const Tp&);
        void setHeight(const Tp&);

        Point_2D<Tp> getTopLeft();        
        Point_2D<Tp> getTopRight();
        Point_2D<Tp> getBottomLeft();
        Point_2D<Tp> getBottomRight();

        void setTopLeft(const Point_2D<Tp>&);
        void setTopRight(const Point_2D<Tp>&);
        void setBottomLeft(const Point_2D<Tp>&);
        void setBottomRight(const Point_2D<Tp>&);

        Tp area();
        Point_2D<double> center();

        ~Rectangle();
    };
}
#endif