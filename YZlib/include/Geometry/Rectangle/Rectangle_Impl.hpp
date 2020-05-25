#ifndef YZ_RECTANGLE_IMPL_HPP
#define YZ_RECTANGLE_IMPL_HPP
#include <iostream>
#include "Geometry/Rectangle.h"
namespace YZlib{    
    template<typename Tp>
    Rectangle<Tp>::Rectangle()
        :_points(std::make_pair<<Point2D<Tp>(Point2D<Tp>(0,0),Point2D<Tp>(0,0)))
    {
    }
    template<typename Tp>
    Rectangle<Tp>::Rectangle(const Rectangle& rect)
        :_points(rect._points)
    {
    }
    template<typename Tp>
    Rectangle<Tp>::Rectangle(Rectangle&& rect)
        :_points(std::move(rect._points))
    {
    }
    template<typename Tp>
    Rectangle<Tp>::Rectangle(Rectangle&& rect)
        :_points(std::move(rect._points))
    {
    }

    template<typename Tp>
    Rectangle<Tp>::~Rectangle()
    {
    }
    
}
#endif