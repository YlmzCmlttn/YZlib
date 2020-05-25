#ifndef YZ_ASSERT_HPP
#define YZ_ASSERT_HPP
#include <iostream>
#include <assert.h>
#include "Core/Debug.hpp"
#define YZ_ASSERT
namespace YZlib{
#if not defined(YZ_ASSERT) && not defined(DEBUG_HPP)
    template <typename ...Args>
    void UNUSED(Args&& ...args)
    {
        (void)(sizeof...(args));
    }
#endif
    void YZ_assert(const bool& _condition,const char* err_msg);
    
    template<typename T>
    void YZ_assert(const bool& _condition,const char* err_msg, T value){
#if defined(YZ_ASSERT)||defined(DEBUG)
        if(!_condition){
            ERROR("YZ_assert :",err_msg,value);
            assert(_condition);
        }
#else
        UNUSED(_condition,err_msg,value);
#endif
    }


    template<typename T, typename... Targs>
    void YZ_assert(const bool& _condition,const char* err_msg, T value, Targs... Fargs){
#if defined(YZ_ASSERT)||defined(DEBUG)
        if(!_condition){
            ERROR("YZ_assert :",err_msg,value,Fargs...);            
            assert(_condition);
        }
#else
        UNUSED(_condition,err_msg,value,Fargs...);
#endif
    }
}
#endif