#include "Linear_Algebra/Matrix/Matrix_Blas.h"
namespace YZlib{
    void inverse(double* A, int N){
        int *IPIV = new int[N+1];
        int LWORK = N*N;
        double *WORK = new double[LWORK];
        int INFO;

        dgetrf_(&N,&N,A,&N,IPIV,&INFO);
        dgetri_(&N,A,&N,IPIV,WORK,&LWORK,&INFO);
        delete IPIV;
        delete WORK;
    }
}