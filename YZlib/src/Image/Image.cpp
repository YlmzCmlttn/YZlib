#include "Image/Image.h"
namespace YZlib{
    Image_::Image_(const Image_& image)
        :width_(image.width_),height_(image.height_),channel_(image.channel_),colorType_(image.colorType_),data_(image.data_)
    {
        IMAGE_INFO_D("Image_(const Image_& image)");
    }
    Image_::Image_(Image_&& image)noexcept
        :width_(image.width_),height_(image.height_),channel_(image.channel_),colorType_(image.colorType_),data_(std::move(image.data_))
    {
        IMAGE_INFO_D("Image_(Image_&& image)");
    }
    Image_::Image_(const std::string& file_name)
    {
        Image_ temp=imread(file_name);
        data_ = std::move(temp.data_);
        channel_=temp.channel_;
        width_=data_.getNumberofCols()/channel_;
        height_=data_.getNumberofRows();
        colorType_=temp.colorType_;
        IMAGE_INFO_D("Image_(const std::string&",file_name,")");
    }
    Image_::Image_(Matrix_<unsigned char>&& data)
        :width_(data.getNumberofCols()/3),height_(data.getNumberofRows()),channel_(3),colorType_(Color_Type::RGB),data_(std::move(data))
    {
        IMAGE_SUCCESS_D("Image_(Matrix_<unsigned char>&& data)");
    }
    Image_::Image_(Matrix_<unsigned char>&& data,const Color_Type& color_type)
        :width_(data.getNumberofCols()/colorType2channel(color_type)),height_(data.getNumberofRows()),channel_(colorType2channel(color_type)),colorType_(color_type),data_(std::move(data))
    {
        IMAGE_INFO_D("Image_(Matrix_<unsigned char>&& data,const Color_Type& color_type)");
    }
    Image_::Image_(Matrix_<unsigned char>&& data,const size_t& channel)
        :width_(data.getNumberofCols()/channel),height_(data.getNumberofRows()),channel_(channel),colorType_(channel2colorType(channel)),data_(std::move(data))
    {
        IMAGE_INFO_D("Image_(Matrix_<unsigned char>&& data,const size_t& channel)");
    }
    Image_::Image_(Matrix_<unsigned char>&& data,const Color_Type& color_type,const size_t& channel)
        :width_(data.getNumberofCols()/channel),height_(data.getNumberofRows()),channel_(channel),colorType_(color_type),data_(std::move(data))
    {
        IMAGE_INFO_D("Image_(Matrix_<unsigned char>&& data,const Color_Type& color_type,const size_t& channel)");
    }
    Image_::Image_(const Matrix_<unsigned char>& data)
        :width_(data.getNumberofCols()/3),height_(data.getNumberofRows()),channel_(3),colorType_(Color_Type::RGB),data_(data)
    {
        IMAGE_INFO_D("Image_(const Matrix_<unsigned char>& data)");
    }
    Image_::Image_(const Matrix_<unsigned char>& data,const Color_Type& color_type)
        :width_(data.getNumberofCols()/colorType2channel(color_type)),height_(data.getNumberofRows()),channel_(colorType2channel(color_type)),colorType_(color_type),data_(data)
    {
        IMAGE_INFO_D("Image_(const Matrix_<unsigned char>& data,const Color_Type& color_type)");
    }
    Image_::Image_(const Matrix_<unsigned char>& data,const size_t& channel)
        :width_(data.getNumberofCols()/channel),height_(data.getNumberofRows()),channel_(channel),colorType_(channel2colorType(channel)),data_(data)
    {
        IMAGE_INFO_D("Image_(const Matrix_<unsigned char>& data,const size_t& channel)");
    }
    Image_::Image_(const Matrix_<unsigned char>& data,const Color_Type& color_type,const size_t& channel)
        :width_(data.getNumberofCols()/channel),height_(data.getNumberofRows()),channel_(channel),colorType_(color_type),data_(data)
    {
        IMAGE_INFO_D("Image_(const Matrix_<unsigned char>& data,const Color_Type& color_type,const size_t& channel)");
    }
    Image_::Image_(const size_t& width,const size_t& height)
        :width_(width),height_(height),channel_(3),colorType_(Color_Type::RGB),data_(Matrix_<unsigned char>(height,width*channel_))
    {
        IMAGE_INFO_D("Image_(const size_t& width,const size_t& height)");
    }
    Image_::Image_(const size_t& width,const size_t& height,const Color_Type& color_type)
        :width_(width),height_(height),channel_(colorType2channel(color_type)),colorType_(color_type),data_(Matrix_<unsigned char>(height,width*channel_))
    {
        IMAGE_INFO_D("Image_(const size_t& width,const size_t& height,const Color_Type& color_type)");
    }
    Image_::Image_(const size_t& width,const size_t& height,const size_t& channel)
        :width_(width),height_(height),channel_(channel),colorType_(channel2colorType(channel)),data_(Matrix_<unsigned char>(height,width*channel_))
    {
        IMAGE_INFO_D("Image_(const size_t& width,const size_t& height,const size_t& channel)");
    }
    Image_::Image_(const size_t& width,const size_t& height,const size_t& channel,const Color_Type& color_type)
        :width_(width),height_(height),channel_(channel),colorType_(color_type),data_(Matrix_<unsigned char>(height,width*channel_))
    {
        IMAGE_INFO_D("Image_(const size_t& width,const size_t& height,const size_t& channel,const Color_Type& color_type)");
    }
    Image_::Image_(const size_t& width,const size_t& height,Matrix_<unsigned char>&& data)
        :width_(width),height_(height),channel_(3),colorType_(Color_Type::RGB),data_(std::move(data))
    {
        IMAGE_INFO_D("Image_(const size_t& width,const size_t& height,Matrix_<unsigned char>&& data)");
    }
    Image_::Image_(const size_t& width,const size_t& height,const Color_Type& color_type,Matrix_<unsigned char>&& data)
        :width_(width),height_(height),channel_(colorType2channel(color_type)),colorType_(color_type),data_(std::move(data))
    {
        IMAGE_INFO_D("Image_(const size_t& width,const size_t& height,const Color_Type& color_type),Matrix_<unsigned char>&& data");
    }
    Image_::Image_(const size_t& width,const size_t& height,const size_t& channel,Matrix_<unsigned char>&& data)
        :width_(width),height_(height),channel_(channel),colorType_(channel2colorType(channel)),data_(std::move(data))
    {
        IMAGE_INFO_D("Image_(const size_t& width,const size_t& height,const size_t& channel,Matrix_<unsigned char>&& data)");
    }
    Image_::Image_(const size_t& width,const size_t& height,const size_t& channel,const Color_Type& color_type,Matrix_<unsigned char>&& data)
        :width_(width),height_(height),channel_(channel),colorType_(color_type),data_(std::move(data))
    {
        IMAGE_INFO_D("Image_(const size_t& width,const size_t& height,const size_t& channel,const Color_Type& color_type,Matrix_<unsigned char>&& data)");
    }
    Image_::Image_(const size_t& width,const size_t& height,const Matrix_<unsigned char>& data)
        :width_(width),height_(height),channel_(3),colorType_(Color_Type::RGB),data_(data)
    {
        IMAGE_INFO_D("Image_(const size_t& width,const size_t& height,Matrix_<unsigned char>&& data)");
    }
    Image_::Image_(const size_t& width,const size_t& height,const Color_Type& color_type,const Matrix_<unsigned char>& data)
        :width_(width),height_(height),channel_(colorType2channel(color_type)),colorType_(color_type),data_(data)
    {
        IMAGE_INFO_D("Image_(const size_t& width,const size_t& height,const Color_Type& color_type),Matrix_<unsigned char>&& data");
    }
    Image_::Image_(const size_t& width,const size_t& height,const size_t& channel,const Matrix_<unsigned char>& data)
        :width_(width),height_(height),channel_(channel),colorType_(channel2colorType(channel)),data_(data)
    {
        IMAGE_INFO_D("Image_(const size_t& width,const size_t& height,const size_t& channel,Matrix_<unsigned char>&& data)");
    }
    Image_::Image_(const size_t& width,const size_t& height,const size_t& channel,const Color_Type& color_type,const Matrix_<unsigned char>& data)
        :width_(width),height_(height),channel_(channel),colorType_(color_type),data_(data)
    {
        IMAGE_INFO_D("Image_(const size_t& width,const size_t& height,const size_t& channel,const Color_Type& color_type,Matrix_<unsigned char>&& data)");
    }
    Image_::~Image_(){        
    }
}