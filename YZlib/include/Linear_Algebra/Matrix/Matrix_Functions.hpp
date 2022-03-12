#ifndef YZ_LINEAR_ALGEBRA_MATRIX_FUNCTIONS_HPP
#define YZ_LINEAR_ALGEBRA_MATRIX_FUNCTIONS_HPP
#include <math.h>
#include <chrono>
#include <random>

#include "Core/Timer.h"
#include "Linear_Algebra/Matrix/Matrix.h"
#include "Linear_Algebra/Matrix/Matrix_Debug.hpp"
#include "Core/Assert.hpp"
#include "Linear_Algebra/Matrix/Matrix_Blas.h"
namespace YZlib{
    //Trigonometric functions
    template<typename Tp_>
    Matrix_<Tp_> cos(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::cos(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> sin(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::sin(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> tan(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::tan(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> acos(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::acos(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> asin(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::asin(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> atan(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::atan(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> atan2(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::atan2(a);});
        return std::move(_ret);
    }
    //Hyperbolic functions
    template<typename Tp_>
    Matrix_<Tp_> cosh(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::cosh(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> sinh(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::sinh(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> tanh(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::tanh(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> acosh(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::acosh(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> asinh(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::asinh(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> atanh(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::atanh(a);});
        return std::move(_ret);
    }
    //Exponential and logarithmic functions
    template<typename Tp_>
    Matrix_<Tp_> exp(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::exp(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> log(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::log(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> log10(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::log10(a);});
        return std::move(_ret);
    }
    //Power functions
    template<typename Tp_>
    Matrix_<Tp_> pow(const Matrix_<Tp_>&matrixA,const Matrix_<Tp_>&matrixB){
        Matrix_<Tp_> _ret(matrixA);
        _ret.thread_operator_call(matrixB,[](Tp_ a,Tp_ b){return ::pow(a,b);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> pow(const Matrix_<Tp_>&matrix,const Tp_& B){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[B](Tp_ a){return ::pow(a,B);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> sqrt(const Matrix_<Tp_>&matrixA,const Matrix_<Tp_>&matrixB){
        Matrix_<Tp_> _ret(matrixA);
        _ret.thread_operator_call(matrixB,[](Tp_ a,Tp_ b){return ::sqrt(a,b);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> sqrt(const Matrix_<Tp_>&matrix,const Tp_& B){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[B](Tp_ a){return ::sqrt(a,B);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> hypot(const Matrix_<Tp_>&matrixA,const Matrix_<Tp_>&matrixB){
        Matrix_<Tp_> _ret(matrixA);
        _ret.thread_operator_call(matrixB,[](Tp_ a,Tp_ b){return ::hypot(a,b);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> hypot(const Matrix_<Tp_>&matrix,const Tp_& B){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[B](Tp_ a){return ::hypot(a,B);});
        return std::move(_ret);
    }
    //Rounding and remainder functions 
    template<typename Tp_>
    Matrix_<Tp_> ceil(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::ceil(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> floor(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::floor(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> round(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::round(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> fmod(const Matrix_<Tp_>&matrixA,const Matrix_<Tp_>&matrixB){
        Matrix_<Tp_> _ret(matrixA);
        _ret.thread_operator_call(matrixB,[](Tp_ a,Tp_ b){return ::fmod(a,b);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> fmod(const Matrix_<Tp_>&matrix,const Tp_& B){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[B](Tp_ a){return ::fmod(a,B);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> trunc(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::trunc(a);});
        return std::move(_ret);
    }
    //Other functions
    template<typename Tp_>
    Matrix_<Tp_> abs(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return ::abs(a);});
        return std::move(_ret);
    }
    template<typename Tp_>
    Matrix_<Tp_> sigmoid(const Matrix_<Tp_> &matrix){
        Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
        _ret.thread_operator_call(matrix.data_,[](Tp_ a){return 1.0f/(1.0f+::exp(-a));});
        return std::move(_ret);
    }

    template<typename Tp_>
    Tp_ sum(const Matrix_<Tp_> &matrix){        
        return matrix.sum();
    }

    template <typename Tp_>
    std::variant<Matrix_<Tp_>,Tp_> sum(const Matrix_<Tp_> &matrix,bool keepDims){
        if(!keepDims){
            Matrix_<Tp_> r_t(1);
            Tp_ _t=0;
            for(uint i=0;i<matrix.size;i++){
                _t=_t+matrix.get(i);
            }
            r_t[0]=_t;
            return r_t;
        }else{            
            return sum(matrix);
        }
    }


    template<typename Tp_>
    Tp_ mean(const Matrix_<Tp_> &matrix){        
        return matrix.sum()/uint(matrix.size_);
    }
    //Horizontal concoat
    //Vertical concat
    //linspace
    // template<typename Tp_>
    // Matrix_<Tp_> rand(const Matrix_<Tp_> &matrix){
    //     Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);
    //     _ret.thread_operator_call(matrix.data_,[](Tp_ a){return (Tp_)::rand()/(Tp_)RAND_MAX;});
    //     return std::move(_ret);
    // }
    // template<typename Tp_>
    // Matrix_<Tp_> randn(const Matrix_<Tp_> &matrix,unsigned seed=std::chrono::system_clock::now().time_since_epoch().count()){
    //     std::default_random_engine generator(seed);
    //     std::normal_distribution<double> distribution (0.0,1.0);
    //     Matrix_<Tp_> _ret(matrix.rows_,matrix.cols_,matrix.majorOrder_,matrix.parallel_);        
    //     _ret.thread_operator_call(matrix.data_,[&generator,&distribution](){
    //         return distribution(generator);});
    //     return std::move(_ret);
    // }

    //rand
    //randn
    //sum keepdims
    //sigmoid DONE!
    //relu
    //muliply DONE!
    //inverse DONE!
    //dot product

    template<typename Tp_>
    Matrix_<Tp_> mult(const Matrix_<Tp_> &_A,const Matrix_<Tp_> &_B){        
        Matrix_<double> _C(_A.getNumberofRows(),_B.getNumberofCols());
        // Matrix_<double> A_tmp = Matrix_<Tp_>(_A);
        // Matrix_<double> B_tmp = Matrix_<Tp_>(_B); 

        {
            cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,_A.getNumberofRows(), _B.getNumberofCols(), _A.getNumberofCols(), 1.0,
            (const double*)(_A.getConstData()), _A.getNumberofCols(),
            (const double*)(_B.getConstData()), _B.getNumberofCols(), 0.0,
            (double*)(_C.getData()), _B.getNumberofCols());
        }
        

        return Matrix_<Tp_>(_C);
    }
    // template<typename Tp_>
    // Matrix_<Tp_> mult(const Matrix_<Tp_> &_A,const Matrix_<Tp_> &_B){
    //     Matrix_<Tp_> _t(_A.rows(),_B.cols());
    //     if(_A.cols()==_B.rows()){
    //         for(uint i=0;i<_A.rows();i++){
    //             for(uint j=0;j<_B.cols();j++){
    //                 for(uint k=0;k<_A.cols();k++){
    //                     _t(i,j)+=_A.get(i,k)*_B.get(k,j);
    //                 }
    //             }   
    //         }
    //     }
    //     return _t;
        
    // }
    template<typename Tp_>
    Matrix_<double> inve(const Matrix_<Tp_>& _A){        
        Matrix_<double> A_tmp = Matrix_<Tp_>(_A);
        inverse(A_tmp.getConstData(),A_tmp.getSize().size()/2);
        return A_tmp;
    }
}
#endif