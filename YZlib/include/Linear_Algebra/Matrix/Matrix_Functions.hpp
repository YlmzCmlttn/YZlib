#ifndef YZ_LINEAR_ALGEBRA_MATRIX_FUNCTIONS_HPP
#define YZ_LINEAR_ALGEBRA_MATRIX_FUNCTIONS_HPP
#include <math.h>
#include "Linear_Algebra/Matrix.h"
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


    //Horizontal concoat
    //Vertical concat
    //linspace
    
    //rand
    //randn
    //sum keepdims
    //sigmoid
    //relu
    //muliply
    //inverse
    //dot product

    template<typename Tp_>
    Matrix_<Tp_> mult(const Matrix_<Tp_> &_A,const Matrix_<Tp_> &_B){
        Matrix_<double> _C(_A.getNumberofRows(),_B.getNumberofCols());
        Matrix_<double> A_tmp = Matrix_<Tp_>(_A);
        Matrix_<double> B_tmp = Matrix_<Tp_>(_B); 

        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,_A.getNumberofRows(), _B.getNumberofCols(), _A.getNumberofCols(), 1.0,
            (const double*)(A_tmp.getConstData().get()), _A.getNumberofCols(),
            (const double*)(B_tmp.getConstData().get()), _B.getNumberofCols(), 0.0,
            (double*)(_C.getData().get()), _B.getNumberofCols());
        Matrix_<Tp_> _ret = Matrix_<Tp_>(_C);
        return _ret;
    }
    template<typename Tp_>
    Matrix_<double> inve(const Matrix_<Tp_>& _A){        
        Matrix_<double> A_tmp = Matrix_<Tp_>(_A);
        inverse(A_tmp.getConstData().get(),A_tmp.getSize().size()/2);
        return A_tmp;
    }
}
#endif