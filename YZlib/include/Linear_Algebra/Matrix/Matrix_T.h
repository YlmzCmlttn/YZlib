#ifndef YZ_MATRIX_T_HPP
#define YZ_MATRIX_T_HPP
#include <iostream>
#include "Linear_Algebra/Matrix/Matrix.h"
namespace YZlib{
    template<typename _T,uint rows,uint cols>
    class _Matrix : public Matrix_<_T>
    {
    public:
        _Matrix(/* args */):Matrix_<_T>(rows,cols){}
        _Matrix(_T _data):Matrix_<_T>(rows,cols,_data){}
        _Matrix(const std::initializer_list<std::initializer_list<_T>>& l):
            Matrix_<_T>(l){}
        ~_Matrix(){};
    };
}

#endif