#ifndef YZ_RECTANGLE_IMPL_HPP
#define YZ_RECTANGLE_IMPL_HPP
#include <iostream>
#include "Geometry/Rectangle.h"
namespace YZlib{    
    template<typename Tp>
    Rectangle<Tp>::Rectangle()
        :x(0),y(0),width(0),height(0)
    {
    }
    template<typename Tp>
    Rectangle<Tp>::Rectangle(const Rectangle& rect)
        :x(rect.x),y(rect.y),width(rect.width),height(rect.height)
    {
    }
    template<typename Tp>
    Rectangle<Tp>::Rectangle(Rectangle&& rect)noexcept
        :x(std::exchange(rect.x)),y(std::exchange(rect.y)),width(std::exchange(rect.width)),height(std::exchange(rect.height))
    {
    }
    template<typename Tp>
    Rectangle<Tp>::Rectangle(const Tp& _x,const Tp& _y,const Tp& _width, const Tp& _height)
        :x(_x),y(_y),width(_width),height(_height)
    {
    }
    template<typename Tp>
    Rectangle<Tp>& Rectangle<Tp>::operator = (const Rectangle<Tp>& rect){
        return *this = Rectangle<Tp>(rect);
    }
    template<typename Tp>
    Rectangle<Tp>& Rectangle<Tp>::operator = (Rectangle<Tp>&&rect)noexcept{
        std::swap(x, rect.x);
        std::swap(y, rect.y);
        std::swap(width, rect.width);
        std::swap(height, rect.height);
        return *this;
    }
    template<typename Tp>
    Rectangle<Tp>::~Rectangle()
    {
    }
    
}
#endif