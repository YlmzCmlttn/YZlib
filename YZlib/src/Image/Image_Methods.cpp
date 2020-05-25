#include "Image/Image.h"
namespace YZlib{
    size_t Image_::colorType2channel(const Color_Type& colorType){
        if(colorType==Color_Type::GRAY){
            return 1;
        }else if(colorType==Color_Type::GRAYA){
            return 2;
        }else if(colorType==Color_Type::RGB){
            return 3;
        }else if(colorType==Color_Type::RGBA){
            return 4;
        }else{
            return 4;
        }
    }
    Color_Type Image_::channel2colorType(const size_t& channel){
        if(channel==1){
            return Color_Type::GRAY;
        }else if(channel==2){
            return Color_Type::GRAYA;
        }else if(channel==3){
            return Color_Type::RGB;
        }else if(channel==4){
            return Color_Type::RGBA;
        }else{
            return Color_Type::RGBA;
        }
    }
    unsigned char Image_::get(const size_t& index)const{
        return this->data_.get(index);
    }
    unsigned char Image_::get(const size_t& row,const size_t& col)const{
        YZ_assert(this->channel_==1,"this image channel is not equal 1 it is {yz} \nyou must use operator()(const size_t& row,const size_t& col,const size_t& channel)",this->channel_);
        return this->data_.get(row,col);
    }
    unsigned char Image_::get(const size_t& row,const size_t& col,const size_t& channel)const{
        YZ_assert(((this->channel_<5)&&(this->channel_>0)),"this image channel is not (this->channel_<5)&&(this->channel_>0) it is {yz}",this->channel_);
        return this->data_.get(row,this->channel_*col+channel);
    }
    void Image_::set(const size_t& index,const unsigned char& value){
        operator[](index)=value;
    }
    void Image_::set(const size_t& row,const size_t& col,const unsigned char& value){
        operator()(row,col)=value;
    }
    void Image_::set(const size_t& row,const size_t& col,const size_t& channel,const unsigned char& value){
        operator()(row,col,channel)=value;
    }
    size_t Image_::getWidth()const{
        return width_;
    }
    void Image_::setWidth(const size_t& width){
        width_=width;
    }
    size_t Image_::getHeight()const{
        return height_;
    }
    void Image_::setHeight(const size_t& height){
        height_=height;
    }
    size_t Image_::getChannel()const{
        return channel_;
    }
    void Image_::setChannel(const size_t& channel){
        channel_=channel;
    }
    Size Image_::getSize()const{
        return Size(height_,width_);
    }
    Color_Type Image_::getColorType()const{
        return colorType_;
    }
    void Image_::setColorType(const Color_Type& colorType){
        colorType_=colorType;
    }
    Matrix_<unsigned char>& Image_::getData(){
        return data_;
    }
    const Matrix_<unsigned char>& Image_::getConstData()const{
        return data_;
    }
    Matrix_<unsigned char>&& Image_::moveData(){
        return std::move(data_);
    }
    void Image_::setData(const Matrix_<unsigned char>& data){
        data_=data;
    }
    void Image_::setData(Matrix_<unsigned char>&& data){
        data_=std::move(data);
    }
}