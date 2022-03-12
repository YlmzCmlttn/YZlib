#ifndef YZ_LINEAR_ALGEBRA_MATRIX_IMPL_HPP
#define YZ_LINEAR_ALGEBRA_MATRIX_IMPL_HPP
#include "Linear_Algebra/Matrix/Matrix.h"
#include "Linear_Algebra/Matrix/Matrix_Debug.hpp"
#include "Core/Assert.hpp"
namespace YZlib{
    template <typename Tp>
    Matrix_<Tp>::Matrix_()
        :rows_(0),cols_(0),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(Major_Order::Row_Major),parallel_(Parallel::Parallel)
    {
        MATRIX_INFO_D("Matrix_() constructor");
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const Matrix_& _m)
        :rows_(_m.rows_),cols_(_m.cols_),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(_m.majorOrder_),parallel_(_m.parallel_)
    {
        MATRIX_INFO_D("Matrix_(const Matrix_& _m) constructor");
        copyData(_m.data_);
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(Matrix_&& _m)noexcept
        :rows_(_m.rows_),cols_(_m.cols_),size_(rows_*cols_),data_(std::move(_m.data_)),majorOrder_(_m.majorOrder_),parallel_(_m.parallel_)
    {
        MATRIX_SUCCESS_D("Matrix_(Matrix_&& _m) constructor");
        _m.rows_=0;
        _m.cols_=0;
        _m.size_=0;
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const Parallel& parallel)
        :rows_(0),cols_(0),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(Major_Order::Row_Major),parallel_(parallel)
    {
        MATRIX_INFO_D("Matrix_(const Parallel& parallel) constructor");
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const Major_Order& major_order)
        :rows_(0),cols_(0),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(major_order),parallel_(Parallel::Parallel)
    {
        MATRIX_INFO_D("Matrix_(const Major_Order& major_order) constructor");
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const Major_Order& major_order,const Parallel& parallel)
        :rows_(0),cols_(0),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(major_order),parallel_(parallel)
    {
        MATRIX_INFO_D("Matrix_(const Major_Order& major_order,const Parallel& parallel) constructor");
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows)
        :rows_(rows),cols_(1),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(Major_Order::Row_Major),parallel_(Parallel::Parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows) constructor");
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const Parallel& parallel)
        :rows_(rows),cols_(1),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(Major_Order::Row_Major),parallel_(parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const Parallel& parallel) constructor");
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const Major_Order& major_order)
        :rows_(rows),cols_(1),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(major_order),parallel_(Parallel::Parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const Major_Order& major_order) constructor");
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const Major_Order& major_order,const Parallel& parallel)
        :rows_(rows),cols_(1),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(major_order),parallel_(parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const Major_Order& major_order,const Parallel& parallel) constructor");
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const size_t& cols)
        :rows_(rows),cols_(cols),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(Major_Order::Row_Major),parallel_(Parallel::Parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const size_t& cols) constructor");
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const size_t& cols,const Parallel& parallel)
        :rows_(rows),cols_(cols),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(Major_Order::Row_Major),parallel_(parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const size_t& cols,const Parallel& parallel) constructor");
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const size_t& cols,const Major_Order& major_order)
        :rows_(rows),cols_(cols),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(major_order),parallel_(Parallel::Parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const size_t& cols,const Major_Order& major_order) constructor");
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const size_t& cols,const Major_Order& major_order,const Parallel& parallel)
        :rows_(rows),cols_(cols),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(major_order),parallel_(parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const size_t& cols,const Major_Order& major_order,const Parallel& parallel) constructor");
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const size_t& cols,const Tp& val)
        :rows_(rows),cols_(cols),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(Major_Order::Row_Major),parallel_(Parallel::Parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const size_t& cols,const Tp& val) constructor");
        fill(val);
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const size_t& cols,const Tp& val,const Parallel& parallel)
        :rows_(rows),cols_(cols),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(Major_Order::Row_Major),parallel_(parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const size_t& cols,const Tp& val,const Major_Order& major_order) constructor");
        fill(val);
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const size_t& cols,const Tp& val,const Major_Order& major_order)
        :rows_(rows),cols_(cols),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(major_order),parallel_(Parallel::Parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const size_t& cols,const Tp& val,const Major_Order& major_order) constructor");
        fill(val);
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const size_t& cols,const Tp& val,const Major_Order& major_order,const Parallel& parallel)
        :rows_(rows),cols_(cols),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(major_order),parallel_(parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const size_t& cols,const Tp& val,const Major_Order& major_order) constructor");
        fill(val);
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const size_t& cols,const std::unique_ptr<Tp[]>& data)
        :rows_(rows),cols_(cols),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(Major_Order::Row_Major),parallel_(Parallel::Parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const size_t& cols,const std::unique_ptr<Tp[]>& data) constructor");
        copyData(data);
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const size_t& cols,const std::unique_ptr<Tp[]>& data,const Parallel& parallel)
        :rows_(rows),cols_(cols),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(Major_Order::Row_Major),parallel_(parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const size_t& cols,const std::unique_ptr<Tp[]>& data,const Parallel& parallel) constructor");
        copyData(data);
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const size_t& cols,const std::unique_ptr<Tp[]>& data,const Major_Order& major_order)
        :rows_(rows),cols_(cols),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(major_order),parallel_(Parallel::Parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const size_t& cols,const std::unique_ptr<Tp[]>& data,const Major_Order& major_order) constructor");
        copyData(data);
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const size_t& cols,const std::unique_ptr<Tp[]>& data,const Major_Order& major_order,const Parallel& parallel)
        :rows_(rows),cols_(cols),size_(rows_*cols_),data_(new Tp[size_]),majorOrder_(major_order),parallel_(parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const size_t& cols,const std::unique_ptr<Tp[]>& data,const Major_Order& major_order,const Parallel& parallel) constructor");
        copyData(data);
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const size_t& cols,std::unique_ptr<Tp[]>&& data)
        :rows_(rows),cols_(cols),size_(rows_*cols_),data_(std::move(data)),majorOrder_(Major_Order::Row_Major),parallel_(Parallel::Parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const size_t& cols,std::unique_ptr<Tp[]>&& data) constructor");
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const size_t& cols,std::unique_ptr<Tp[]>&& data,const Parallel& parallel)
        :rows_(rows),cols_(cols),size_(rows_*cols_),data_(std::move(data)),majorOrder_(Major_Order::Row_Major),parallel_(parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const size_t& cols,std::unique_ptr<Tp[]>&& data,const Parallel& parallel) constructor");        
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const size_t& cols,std::unique_ptr<Tp[]>&& data,const Major_Order& major_order)
        :rows_(rows),cols_(cols),size_(rows_*cols_),data_(std::move(data)),majorOrder_(major_order),parallel_(Parallel::Parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const size_t& cols,std::unique_ptr<Tp[]>&& data,const Major_Order& major_order) constructor");
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const size_t& rows,const size_t& cols,std::unique_ptr<Tp[]>&& data,const Major_Order& major_order,const Parallel& parallel)
        :rows_(rows),cols_(cols),size_(rows_*cols_),data_(std::move(data)),majorOrder_(major_order),parallel_(parallel)
    {
        MATRIX_INFO_D("Matrix_(const size_t& rows,const size_t& cols,std::unique_ptr<Tp[]>&& data,const Major_Order& major_order,const Parallel& parallel) constructor");        
    }
    template <typename Tp>
    Matrix_<Tp>::Matrix_(const std::initializer_list<std::initializer_list<Tp>>& l)
        :majorOrder_(Major_Order::Row_Major),parallel_(Parallel::Parallel)
    {
        MATRIX_INFO_D("Matrix_(const std::initializer_list<std::initializer_list<Tp>>& l");
        std::vector<std::initializer_list<Tp>> setVec = l;
        std::vector<std::vector<Tp>> v;
        for(auto i = setVec.begin(); i != setVec.end(); i++){
            v.push_back(std::vector<Tp>(*i));
        }
        uint col_size=0;
        bool first_check =true;
        uint row_size = l.size();
        for(const auto& v1:v){
            if(first_check){
                col_size=v1.size();
                first_check=false;
            }
            assert(col_size=v1.size());
            col_size=v1.size();
        }
        this->cols_=col_size;
        this->rows_=row_size;
        this->size_=this->cols_*this->rows_;
        data_ = new Tp[this->size_];
        uint _index=0;
        for(const auto& v1:v)        {
            for(const auto& v2:v1){
                this->data_[_index++]=v2;
            }
        }
    }
    template <typename Tp>
    Matrix_<Tp>::~Matrix_()
    {
        if(data_!= nullptr)
            delete[] data_;
    }
}
#endif