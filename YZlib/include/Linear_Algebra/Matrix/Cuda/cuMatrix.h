/** -------------------------------------------------------------------------
 *  Copyright (C) 2020 CYVision
 *  All rights reserved.
 *  -------------------------------------------------------------------------
 *  This document contains proprietary information belonging to CYVision.
 *  Passing on and copying of this document, use and communication of its
 *  contents is not permitted without prior written authorization.
 *  -------------------------------------------------------------------------
 *  @author Cemalettin YILMAZ <cemal.yilmaz@cyvision.com>
 *  -------------------------------------------------------------------------
 */
#ifndef YZLIB_LINEAR_ALGEBRA_CUDA_CU_MATRIX_H
#define YZLIB_LINEAR_ALGEBRA_CUDA_CU_MATRIX_H
#include <iostream>
#include "Linear_Algebra/Matrix/Matrix_.h"
#include <memory>
#include <cuda_runtime.h>
#include <cuda.h>
namespace YZlib{
    template<typename _T>
    class cuMatrix_
    {
    private:
        size_t rows_;
        size_t cols_;
        size_t size_;
        std::unique_ptr<Tp[]> data_;
        Major_Order majorOrder_;
        Parallel parallel_;
    public:
        cuMatrix_();
        cuMatrix_(const cuMatrix_&);
        cuMatrix_(cuMatrix_&&) noexcept;
        cuMatrix_(const Parallel&);
        cuMatrix_(const Major_Order&);
        cuMatrix_(const Major_Order&,const Parallel&);
        cuMatrix_(const size_t&);
        cuMatrix_(const size_t&,const Parallel&);
        cuMatrix_(const size_t&,const Major_Order&);
        cuMatrix_(const size_t&,const Major_Order&,const Parallel&);
        cuMatrix_(const size_t&,const size_t&);
        cuMatrix_(const size_t&,const size_t&,const Parallel&);
        cuMatrix_(const size_t&,const size_t&,const Major_Order&);
        cuMatrix_(const size_t&,const size_t&,const Major_Order&,const Parallel&);
        cuMatrix_(const size_t&,const size_t&,const Tp&);
        cuMatrix_(const size_t&,const size_t&,const Tp& val,const Parallel&);
        cuMatrix_(const size_t&,const size_t&,const Tp&,const Major_Order&);
        cuMatrix_(const size_t&,const size_t&,const Tp& val,const Major_Order&,const Parallel&);
        cuMatrix_(const size_t&,const size_t&,const std::unique_ptr<Tp[]>&);
        cuMatrix_(const size_t&,const size_t&,const std::unique_ptr<Tp[]>&,const Parallel&);
        cuMatrix_(const size_t&,const size_t&,const std::unique_ptr<Tp[]>&,const Major_Order&);
        cuMatrix_(const size_t&,const size_t&,const std::unique_ptr<Tp[]>&,const Major_Order&,const Parallel&);
        cuMatrix_(const size_t&,const size_t&,std::unique_ptr<Tp[]>&&);
        cuMatrix_(const size_t&,const size_t&,std::unique_ptr<Tp[]>&&,const Parallel&);
        cuMatrix_(const size_t&,const size_t&,std::unique_ptr<Tp[]>&&,const Major_Order&);
        cuMatrix_(const size_t&,const size_t&,std::unique_ptr<Tp[]>&&,const Major_Order&,const Parallel&);
        cuMatrix_(const std::initializer_list<std::initializer_list<Tp>>& l);
        ~cuMatrix_();

    private:
    };    
}
#endif