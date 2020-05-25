#ifndef YZ_LINEAR_ALGEBRA_MATRIX_METHODS_HPP
#define YZ_LINEAR_ALGEBRA_MATRIX_METHODS_HPP
#include "Linear_Algebra/Matrix.h"
#include "Linear_Algebra/Matrix/Matrix_Debug.hpp"
#include "Core/Assert.hpp"
#include "Thread/Thread_Function.hpp"
namespace YZlib{
    //Methods
    //public;
    template <typename Tp>
    Tp Matrix_<Tp>::get(const size_t& index)const{
        return data_[index];
    }
    template <typename Tp>
    void Matrix_<Tp>::set(const size_t& index,const Tp& data){
        data_[index]=data;
    }
    template <typename Tp>
    Tp Matrix_<Tp>::get(const size_t& row,const size_t& col)const{
        return data_[from2Dto1D(row,col,this->getSize(),this->majorOrder_)];
    }
    template <typename Tp>
    void Matrix_<Tp>::set(const size_t& row,const size_t& col,const Tp& data){
        data_[from2Dto1D(row,col,this->getSize(),this->majorOrder_)]=data;
    }
    template <typename Tp>
    size_t Matrix_<Tp>::getNumberofRows()const{
        return rows_;
    }
    template <typename Tp>
    void Matrix_<Tp>::setNumberofRows(const size_t& rows){
        rows_=rows;
    }
    template <typename Tp>
    size_t Matrix_<Tp>::getNumberofCols()const{
        return cols_;
    }
    template <typename Tp>
    void Matrix_<Tp>::setNumberofCols(const size_t& cols){
        cols_=cols;
    }
    template <typename Tp>
    Size Matrix_<Tp>::getSize()const{
        return Size(rows_,cols_);
    }
    template <typename Tp>
    Major_Order Matrix_<Tp>::getMajorOrder()const{
        return majorOrder_;
    }
    template <typename Tp>
    void Matrix_<Tp>::setMajorOrder(const Major_Order& majorOrder){
        majorOrder_=majorOrder;
    }
    template <typename Tp>
    Parallel Matrix_<Tp>::getParallel()const{
        return parallel_;
    }
    template <typename Tp>
    void Matrix_<Tp>::setParallel(const Parallel& parallel){
        parallel_=parallel;
    }
    //protected;
    template <typename Tp>
    const std::unique_ptr<Tp[]>& Matrix_<Tp>::getConstData()const{
        return data_;
    }
    template <typename Tp>
    std::unique_ptr<Tp[]>& Matrix_<Tp>::getData(){
        return data_;
    }
    template <typename Tp>
    std::unique_ptr<Tp[]>&& Matrix_<Tp>::moveData(){
        return std::move(data_);
    }
    //private:
    template <typename Tp>
    void Matrix_<Tp>::copyData(const std::unique_ptr<Tp[]>& _data){
        MATRIX_WARNING_D("copyData(const std::unique_ptr<Tp[]>& _data)");
        std::function<Tp(Tp)> f = [](Tp a){return a;};
        thread_operator_call(_data,f);    
    }    
    template <typename Tp>void Matrix_<Tp>::fill(const Tp& val){
        MATRIX_INFO_D("fill(const Tp& ",val,")");
        std::function<Tp(Tp)> f = [](Tp a){return a;};
        thread_operator_call(val,f);
    }
    template<typename Tp>
    void Matrix_<Tp>::thread_operator_call(const Tp &_m, const std::function<Tp(Tp,Tp)>& f){
        if(check_parallel()){
            thread_wrapper<Tp,Tp>(f,this->size_,NUM_OF_THREAD,this->data_,this->data_,_m);
        }else{
            for(uint i=0;i<this->size_;i++){
                this->data_[i]=f(this->data_[i],_m);
            }
        }
    }
    template<typename Tp>
    void Matrix_<Tp>::thread_operator_call(const Matrix_<Tp> &_m, const std::function<Tp(Tp,Tp)>& f){
        if(check_parallel()){
            thread_wrapper<Tp,Tp>(f,this->size_,NUM_OF_THREAD,this->data_.get(),this->data_.get(),_m.data_.get());
        }else{
            for(uint i=0;i<this->size_;i++){
                this->data_[i]=f(this->data_[i],_m.get(i));
            }            
        }
    }
    template<typename Tp>
    void Matrix_<Tp>::thread_operator_call(const std::unique_ptr<Tp[]> &data, const std::function<Tp(Tp)>& f){
        if(check_parallel()){
            thread_wrapper<Tp,Tp>(f,this->size_,NUM_OF_THREAD,this->data_.get(),data.get());
        }else{
            for(uint i=0;i<this->size_;i++){
                this->data_[i]=f(data[i]);
            }            
        }
    }
    template<typename Tp>
    void Matrix_<Tp>::thread_operator_call(const Tp&_m, const std::function<Tp(Tp)>& f){
        if(check_parallel()){
            thread_wrapper<Tp,Tp>(f,this->size_,NUM_OF_THREAD,this->data_.get(),_m);
        }else{
            for(uint i=0;i<this->size_;i++){
                this->data_[i]=f(_m);
            }            
        }
    }
    template<typename Tp>
    bool Matrix_<Tp>::thread_bool_operator_call(const Matrix_<Tp> &_m, const std::function<bool(Tp,Tp)>& f){
        bool ret_ = true;
        if(check_parallel()){
            //thread_wrapper<Tp,Tp>(f,this->size_,NUM_OF_THREAD,this->data_.get(),this->data_.get(),_m.data_.get());
        }else{
            for(uint i=0;i<this->size_;i++){
                if(!(f(this->data_[i],_m.get(i)))){
                    ret_ = false;
                    break;
                }
            }
        }
        return ret_;
    }
    template<typename Tp>
    bool Matrix_<Tp>::check_parallel()const{        
        if(this->parallel_==Parallel::Parallel){
#ifdef PARALLEL_MATRIX
            return true;
#else
            return false;
#endif
        }else{
            return false;
        }        
    }
    
}
#endif