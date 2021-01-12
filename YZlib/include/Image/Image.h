#ifndef YZ_IMAGE_H
#define YZ_IMAGE_H
#include <iostream>
#include "Image/Image_.h"
#include "Linear_Algebra/Matrix.h"
#include "Image/Image_Debug.hpp"
namespace YZlib{
    class Image_
    {
    private:    
        size_t width_;
        size_t height_;        
        size_t channel_;
        Color_Type colorType_;
        Matrix_<unsigned char> data_;
    public:
        Image_();
        Image_(const Image_&);
        Image_(Image_&&)noexcept;
        Image_(const std::string&);
        Image_(Matrix_<unsigned char>&&);
        Image_(Matrix_<unsigned char>&&,const Color_Type&);
        Image_(Matrix_<unsigned char>&&,const size_t&);
        Image_(Matrix_<unsigned char>&&,const Color_Type&,const size_t&);
        Image_(const Matrix_<unsigned char>&);
        Image_(const Matrix_<unsigned char>&,const Color_Type&);
        Image_(const Matrix_<unsigned char>&,const size_t&);
        Image_(const Matrix_<unsigned char>&,const Color_Type&,const size_t&);
        Image_(const size_t&,const size_t&);
        Image_(const size_t&,const size_t&,const Color_Type&);
        Image_(const size_t&,const size_t&,const size_t&);
        Image_(const size_t&,const size_t&,const size_t&,const Color_Type&);
        Image_(const size_t&,const size_t&,Matrix_<unsigned char>&&);
        Image_(const size_t&,const size_t&,const Color_Type&,Matrix_<unsigned char>&&);
        Image_(const size_t&,const size_t&,const size_t&,Matrix_<unsigned char>&&);
        Image_(const size_t&,const size_t&,const size_t&,const Color_Type&,Matrix_<unsigned char>&&);
        Image_(const size_t&,const size_t&,const Matrix_<unsigned char>&);
        Image_(const size_t&,const size_t&,const Color_Type&,const Matrix_<unsigned char>&);
        Image_(const size_t&,const size_t&,const size_t&,const Matrix_<unsigned char>&);
        Image_(const size_t&,const size_t&,const size_t&,const Color_Type&,const Matrix_<unsigned char>&);
        ~Image_();
        
        unsigned char get(const size_t&)const;
        unsigned char get(const size_t&,const size_t&)const;
        unsigned char get(const size_t&,const size_t&,const size_t&)const;
        void set(const size_t&,const unsigned char&);
        void set(const size_t&,const size_t&,const unsigned char&);
        void set(const size_t&,const size_t&,const size_t&,const unsigned char&);

        size_t getWidth()const;
        void setWidth(const size_t&);
        size_t getHeight()const;
        void setHeight(const size_t&);
        size_t getChannel()const;
        void setChannel(const size_t&);
        Size getSize()const;
        void setSize(const Size&);//NOT IMPLEMENTED
        Color_Type getColorType()const;
        void setColorType(const Color_Type&);
        Matrix_<unsigned char>& getData();
        const Matrix_<unsigned char>& getConstData()const;
        Matrix_<unsigned char>&& moveData();
        void setData(const Matrix_<unsigned char>&);
        void setData(Matrix_<unsigned char>&&);

        Image_& operator=(const Image_&);
        Image_& operator=(Image_&&)noexcept;

        unsigned char& operator[](const size_t&);
        unsigned char& operator()(const size_t&,const size_t&);
        unsigned char& operator()(const size_t&,const size_t&,const size_t&);

        friend std::ostream& operator <<(std::ostream&, const Image_&);
        friend std::istream& operator <<(std::istream&, const Image_&);//NOT IMPLEMENTED
        friend std::fstream& operator <<(std::fstream&, const Image_&);//NOT IMPLEMENTED
        friend std::ifstream& operator <<(std::ifstream&, const Image_&);//NOT IMPLEMENTED
        friend std::ofstream& operator <<(std::ofstream&, const Image_&);//NOT IMPLEMENTED
        
    private:
        size_t colorType2channel(const Color_Type&);
        Color_Type channel2colorType(const size_t&);
    };
    typedef Image_ Image;
}
#include "Image/Image_Functions.h"
#endif