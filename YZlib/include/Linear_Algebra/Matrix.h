#ifndef YZ_LINEAR_ALGEBRA_MATRIX_H
#define YZ_LINEAR_ALGEBRA_MATRIX_H
#include <iostream>
#include "Linear_Algebra/Matrix/Matrix.h"
#include "Linear_Algebra/Matrix/Matrix_T.h"

namespace YZlib{
    typedef Matrix_<int> Matrixi;
    typedef Matrix_<float> Matrixf;
    typedef Matrix_<double> Matrixd;
    typedef Matrix_<unsigned char> Matrixuchar;

    typedef _Matrix<int,2,2> Matrix2i;
    typedef _Matrix<int,3,3> Matrix3i;
    typedef _Matrix<int,4,4> Matrix4i;
    typedef _Matrix<float,2,2> Matrix2f;
    typedef _Matrix<float,3,3> Matrix3f;
    typedef _Matrix<float,4,4> Matrix4f;    
    typedef _Matrix<double,2,2> Matrix2d;
    typedef _Matrix<double,3,3> Matrix3d;
    typedef _Matrix<double,4,4> Matrix4d;

    typedef _Matrix<int,2,1> Vector2i;
    typedef _Matrix<int,3,1> Vector3i;    
    typedef _Matrix<int,4,1> Vector4i;
    typedef _Matrix<float,2,1> Vector2f;
    typedef _Matrix<float,3,1> Vector3f;    
    typedef _Matrix<float,4,1> Vector4f;
    typedef _Matrix<double,2,1> Vector2d;
    typedef _Matrix<double,3,1> Vector3d;    
    typedef _Matrix<double,4,1> Vector4d;
    

    typedef _Matrix<int,1,2> RowVector2i;
    typedef _Matrix<int,1,3> RowVector3i;    
    typedef _Matrix<int,1,4> RowVector4i;
    typedef _Matrix<float,1,2> RowVector2f;
    typedef _Matrix<float,1,3> RowVector3f;    
    typedef _Matrix<float,1,4> RowVector4f;
    typedef _Matrix<double,1,2> RowVector2d;
    typedef _Matrix<double,1,3> RowVector3d;    
    typedef _Matrix<double,1,4> RowVector4d;

    typedef Matrixd Matrix;

    typedef Matrix2d Matrix2;
    typedef Matrix3d Matrix3;
    typedef Matrix4d Matrix4;

    typedef Vector2d Vector2;
    typedef Vector3d Vector3;
    typedef Vector4d Vector4;

    typedef RowVector2d RowVector2;
    typedef RowVector3d RowVector3;
    typedef RowVector4d RowVector4;
}
#endif