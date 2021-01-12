#ifndef YZ_LINEAR_ALGEBRA_MATRIX_OPERATORS_HPP
#define YZ_LINEAR_ALGEBRA_MATRIX_OPERATORS_HPP
#include "Linear_Algebra/Matrix/Matrix.h"
#include "Linear_Algebra/Matrix/Matrix_Debug.hpp"
#include "Core/Assert.hpp"
namespace YZlib{  
    //Operators
    template <typename Tp>
    Matrix_<Tp>& Matrix_<Tp>::operator=(const Matrix_& _m)
    {
        MATRIX_INFO_D("operator=(const Matrix_& _m)");
        //if(*this != _m){             
        rows_ = _m.rows_;
        cols_ = _m.cols_;
        size_ = rows_*cols_;
        data_ = std::make_unique<Tp[]>(size_);
        majorOrder_ = _m.majorOrder_;
        parallel_ = _m.parallel_;
        copyData(_m.data_);
        //}
        return *this;
    }
    template <typename Tp>
    Matrix_<Tp>& Matrix_<Tp>::operator=(Matrix_&& _m)noexcept{
        MATRIX_SUCCESS_D("operator=(Matrix_&& _m)");
        rows_ = _m.rows_;
        cols_ = _m.cols_;
        size_ = rows_*cols_;        
        data_ = std::move(_m.data_);
        majorOrder_ = _m.majorOrder_;
        parallel_ = _m.parallel_;
        _m.rows_=0;
        _m.cols_=0;
        _m.size_=0;
        return *this;
    }
    template <typename Tp>
    Tp& Matrix_<Tp>::operator[](const size_t& index){
        YZ_assert(index<size_,"Matrix operator [] is not _index<s.size => {yz} < {yz}",index,size_);
        return data_[index];
    }
    template <typename Tp>
    Tp& Matrix_<Tp>::operator()(const size_t& row,const size_t& col){
        YZ_assert(rows_>row,"Matrix operator (row,col) is not row_>row => {yz} > {yz}",rows_,row);
        YZ_assert(cols_>col,"Matrix operator (row,col) is not col_>col => {yz} > {yz}",cols_,col);
        return operator[](from2Dto1D(row,col,this->getSize(),this->majorOrder_));
    }
    template <typename Tp>
    Matrix_<Tp>& Matrix_<Tp>::operator += (const Matrix_<Tp>&_m){
        thread_operator_call(_m,[](Tp a,Tp b){return a+b;});
        return *this;
    }
    template <typename Tp>
    Matrix_<Tp>& Matrix_<Tp>::operator -= (const Matrix_<Tp>&_m){
        thread_operator_call(_m,[](Tp a,Tp b){return a-b;});
        return *this;
    }
    template <typename Tp>
    Matrix_<Tp>& Matrix_<Tp>::operator *= (const Matrix_<Tp>&_m){
        thread_operator_call(_m,[](Tp a,Tp b){return a*b;});        
        return *this;
    }
    template <typename Tp>
    Matrix_<Tp>& Matrix_<Tp>::operator /= (const Matrix_<Tp>&_m){
        thread_operator_call(_m,[](Tp a,Tp b){return a/b;});
        return *this;
    }
    template <typename Tp>
    Matrix_<Tp>& Matrix_<Tp>::operator %= (const Matrix_<Tp>&_m){
        thread_operator_call(_m,[](Tp a,Tp b){return a^b;});
        return *this;
    }
    template <typename Tp>
    Matrix_<Tp>& Matrix_<Tp>::operator ^= (const Matrix_<Tp>&_m){
        thread_operator_call(_m,[](Tp a,Tp b){return a%b;});
        return *this;
    }
    template <typename Tp>
    Matrix_<Tp> Matrix_<Tp>::operator + (const Matrix_<Tp>&_m)const{
        return std::move(Matrix_<Tp>(*this) += _m);
    }
    template <typename Tp>
    Matrix_<Tp> Matrix_<Tp>::operator - (const Matrix_<Tp>&_m)const{
        return std::move(Matrix_<Tp>(*this) -= _m);
    }
    template <typename Tp>
    Matrix_<Tp> Matrix_<Tp>::operator * (const Matrix_<Tp>&_m)const{
        return std::move(Matrix_<Tp>(*this) *= _m);
    }
    template <typename Tp>
    Matrix_<Tp> Matrix_<Tp>::operator / (const Matrix_<Tp>&_m)const{
        return std::move(Matrix_<Tp>(*this) /= _m);
    }
    template <typename Tp>
    Matrix_<Tp> Matrix_<Tp>::operator % (const Matrix_<Tp>&_m)const{
        return std::move(Matrix_<Tp>(*this) %= _m);
    }
    template <typename Tp>
    Matrix_<Tp> Matrix_<Tp>::operator ^ (const Matrix_<Tp>&_m)const{
        return std::move(Matrix_<Tp>(*this) ^= _m);
    }
    template <typename Tp>
    Matrix_<Tp>& Matrix_<Tp>::operator += (const Tp&_val){
        thread_operator_call(this->data_,[_val](Tp a){return a+_val;});
        return *this;
    }
    template <typename Tp>
    Matrix_<Tp>& Matrix_<Tp>::operator -= (const Tp&_val){
        thread_operator_call(this->data_,[_val](Tp a){return a-_val;});
        return *this;
    }
    template <typename Tp>
    Matrix_<Tp>& Matrix_<Tp>::operator *= (const Tp&_val){
        thread_operator_call(this->data_,[_val](Tp a){return a*_val;});
        return *this;
    }
    template <typename Tp>
    Matrix_<Tp>& Matrix_<Tp>::operator /= (const Tp&_val){
        thread_operator_call(this->data_,[_val](Tp a){return a/_val;});
        return *this;
    }
    template <typename Tp>
    Matrix_<Tp>& Matrix_<Tp>::operator %= (const Tp&_val){
        thread_operator_call(this->data_,[_val](Tp a){return a%_val;});
        return *this;
    }
    template <typename Tp>
    Matrix_<Tp>& Matrix_<Tp>::operator ^= (const Tp&_val){
        thread_operator_call(this->data_,[_val](Tp a){return a^_val;});
        return *this;
    }
    template <typename Tp>
    Matrix_<Tp> Matrix_<Tp>::operator + (const Tp&_val)const{
        return std::move(Matrix_<Tp>(*this) += _val);
    }
    template <typename Tp>
    Matrix_<Tp> Matrix_<Tp>::operator - (const Tp&_val)const{
        return std::move(Matrix_<Tp>(*this) -= _val);
    }
    template <typename Tp>
    Matrix_<Tp> Matrix_<Tp>::operator * (const Tp&_val)const{
        return std::move(Matrix_<Tp>(*this) *= _val);
    }
    template <typename Tp>
    Matrix_<Tp> Matrix_<Tp>::operator / (const Tp&_val)const{
        return std::move(Matrix_<Tp>(*this) /= _val);
    }
    template <typename Tp>
    Matrix_<Tp> Matrix_<Tp>::operator % (const Tp&_val)const{
        return std::move(Matrix_<Tp>(*this) %= _val);
    }
    template <typename Tp>
    Matrix_<Tp> Matrix_<Tp>::operator ^ (const Tp&_val)const{
        return std::move(Matrix_<Tp>(*this) ^= _val);
    }
    template <typename Tp>
    bool Matrix_<Tp>::operator == (const Matrix_<Tp>&_m){
        return thread_bool_operator_call(_m,[](Tp a,Tp b){return a==b;});
    }
    template <typename Tp>
    bool Matrix_<Tp>::operator != (const Matrix_<Tp>&_m){
        return thread_bool_operator_call(_m,[](Tp a,Tp b){return a!=b;});
    }
    template <typename Tp>
    bool Matrix_<Tp>::operator > (const Matrix_<Tp>&_m){
        return thread_bool_operator_call(_m,[](Tp a,Tp b){return a>b;});
    }
    template <typename Tp>
    bool Matrix_<Tp>::operator < (const Matrix_<Tp>&_m){
        return thread_bool_operator_call(_m,[](Tp a,Tp b){return a<b;});
    }
    template <typename Tp>
    bool Matrix_<Tp>::operator >= (const Matrix_<Tp>&_m){
        return thread_bool_operator_call(_m,[](Tp a,Tp b){return a>=b;});
    }
    template <typename Tp>
    bool Matrix_<Tp>::operator <= (const Matrix_<Tp>&_m){
        return thread_bool_operator_call(_m,[](Tp a,Tp b){return a<=b;});
    }
    template <typename Tp>
    Matrix_<Tp>::operator bool()const{
        if((rows_==0)||(cols_==0)||(size_==0)){
            return false;
        }else{
            return true;
        }
    }
    //Conversion
    template <typename Tp>
    template <typename newTp> 
    Matrix_<Tp>::operator Matrix_<newTp>(){
        std::unique_ptr<newTp[]> new_data = std::make_unique<newTp[]>(this->size_);            
        std::copy(this->data_.get(), this->data_.get() + this->size_, new_data.get());
        return Matrix_<newTp>(this->rows_,this->cols_,std::move(new_data),this->majorOrder_,this->parallel_);
    }
    //Friend operator
    template <typename Tp_> 
    Matrix_<Tp_> operator + (const Tp_& _val,const Matrix_<Tp_>& _m){
        Matrix_<Tp_> _ret(_m.rows_,_m.cols_,_m.majorOrder_,_m.parallel_);
        _ret.thread_operator_call(_m.data_,[_val](Tp_ a){return _val+a;});
        return std::move(_ret);
    }
    template <typename Tp_> 
    Matrix_<Tp_> operator - (const Tp_& _val,const Matrix_<Tp_>& _m){
        Matrix_<Tp_> _ret(_m.rows_,_m.cols_,_m.majorOrder_,_m.parallel_);
        _ret.thread_operator_call(_m.data_,[_val](Tp_ a){return _val-a;});
        return std::move(_ret);
    }
    template <typename Tp_> 
    Matrix_<Tp_> operator * (const Tp_& _val,const Matrix_<Tp_>& _m){
        Matrix_<Tp_> _ret(_m.rows_,_m.cols_,_m.majorOrder_,_m.parallel_);
        _ret.thread_operator_call(_m.data_,[_val](Tp_ a){return _val*a;});
        return std::move(_ret);
    }
    template <typename Tp_> 
    Matrix_<Tp_> operator / (const Tp_& _val,const Matrix_<Tp_>& _m){
        Matrix_<Tp_> _ret(_m.rows_,_m.cols_,_m.majorOrder_,_m.parallel_);
        _ret.thread_operator_call(_m.data_,[_val](Tp_ a){return _val/a;});
        return std::move(_ret);
    }
    template <typename Tp_> 
    Matrix_<Tp_> operator % (const Tp_& _val,const Matrix_<Tp_>& _m){
        Matrix_<Tp_> _ret(_m.rows_,_m.cols_,_m.majorOrder_,_m.parallel_);
        _ret.thread_operator_call(_m.data_,[_val](Tp_ a){return _val%a;});
        return std::move(_ret);
    }
    template <typename Tp_> 
    Matrix_<Tp_> operator ^ (const Tp_& _val,const Matrix_<Tp_>& _m){
        Matrix_<Tp_> _ret(_m.rows_,_m.cols_,_m.majorOrder_,_m.parallel_);
        _ret.thread_operator_call(_m.data_,[_val](Tp_ a){return _val^a;});
        return std::move(_ret);
    }
    template <typename Tp_> 
    std::ostream& operator <<(std::ostream& os, const Matrix_<Tp_>& _A){        
        os<<"{";
        for(uint i=0;i<_A.rows_;i++){
            os<<"{";
            for(uint j=0;j<_A.cols_;j++){
                os<<_A.get(i,j);
                if(j!=_A.cols_-1){
                    os<<",";
                }
            }
            if(i==_A.rows_-1){
                os<<"}";
            }else{
                os<<"},\n ";
            }
        }
        os<<"}";
        return os;
    }
}
#endif