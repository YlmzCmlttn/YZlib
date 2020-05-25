#include "Image/Image.h"
#include "Core/Assert.hpp"
namespace YZlib{
    Image_& Image_::operator=(const Image_& image)
    {
        IMAGE_WARNING_D("operator=(const Image_& image)");
        return *this = Image_(image);
    } 
    Image_& Image_::operator=(Image_&& image) noexcept
    {
        IMAGE_SUCCESS_D("operator=(Image_&& image)");
        this->data_=std::move(image.data_);
        this->height_=std::move(image.height_);
        this->width_=std::move(image.width_);
        this->channel_=std::move(image.channel_);
        this->colorType_=std::move(image.colorType_);
        return *this;
    }
    unsigned char& Image_::operator[](const size_t& index)
    {        
        return this->data_[index];
    }
    unsigned char& Image_::operator()(const size_t& row,const size_t& col)
    {
        YZ_assert(this->channel_==1,"this image channel is not equal 1 it is {yz} \nyou must use operator()(const size_t& row,const size_t& col,const size_t& channel)",this->channel_);        
        return this->data_(row,col);
    }
    unsigned char& Image_::operator()(const size_t& row,const size_t& col,const size_t& channel)
    {
        YZ_assert(((this->channel_<5)&&(this->channel_>0)),"this image channel is not (this->channel_<5)&&(this->channel_>0) it is {yz}",this->channel_);
        return this->data_(row,this->channel_*col+channel);
    }
    std::ostream& operator <<(std::ostream& os, const Image_& image){        
        os<<"Width :"<<image.width_<<std::endl;        
        os<<"Height :"<<image.height_<<std::endl;
        os<<"Channel :"<<image.channel_<<std::endl;
        os<<"Image:"<<image.data_;
        return os;
    }
}