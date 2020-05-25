#ifndef YZ_MATRIX_BLAS_H
#define YZ_MATRIX_BLAS_H
#include <iostream>
#include <cblas.h>
extern "C" {    
    void dgetrf_(int* M, int *N, double* A, int* lda, int* IPIV, int* INFO);
    void dgetri_(int* N, double* A, int* lda, int* IPIV, double* WORK, int* lwork, int* INFO);
}
namespace YZlib{
    void inverse(double* A, int N);    
}
#endif