#include "Core/Size.h"
namespace YZlib{
    Size::Size():
        rows(0),cols(0),size_(rows*cols)
    {
    }
    Size::Size(const uint& _rows,const uint& _cols):
        rows(_rows),cols(_cols),size_(rows*cols)
    {
    }
    void Size::update(){
        size_ = rows*cols;
    }
    uint Size::size(){
        update();
        return size_;
    }
    
}