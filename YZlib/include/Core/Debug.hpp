#ifndef DEBUG_HPP
#define DEBUG_HPP
#include <iostream>
#include <string>
#include <mutex>
#include <bitset>
#include "Core/Print.hpp"
#ifndef PRINT_PROP
#define INFO_PRINT
#define ERROR_PRINT
#define WARNING_PRINT
#define SUCCESS_PRINT
#endif
#ifndef DEBUG_PRINT_PROP
#define INFO_DEBUG_PRINT
#define ERROR_DEBUG_PRINT
#define WARNING_DEBUG_PRINT
#define SUCCESS_DEBUG_PRINT
#endif
#ifdef DEBUG_PRINT_OFF
#undef ERROR_DEBUG_PRINT
#undef WARNING_DEBUG_PRINT
#undef SUCCESS_DEBUG_PRINT
#undef INFO_DEBUG_PRINT
#endif
namespace YZlib{
    template <typename ...Args>
    void UNUSED(Args&& ...args)
    {
        (void)(sizeof...(args));
    }
    template <class ...Args>
    void INFO(const Args& ...args){            
#ifdef INFO_PRINT
        print_(args...);
#else
        UNUSED(args...);
#endif
    }
    template <class ...Args>
    void SUCCESS(const Args& ...args){
#ifdef SUCCESS_PRINT
        print_(Print(BG_GREEN),Print(FG_WHITE),Print(BOLD),args...,Print(DEFAULT));  
#else
        UNUSED(args...);
#endif
    }
    template <class ...Args>
    void WARNING(const Args& ...args){
#ifdef WARNING_PRINT
        print_(Print(FG_YELLOW),Print(BOLD),args...,Print(DEFAULT)); 
#else
        UNUSED(args...);           
#endif
    }
    template <class ...Args>
    void ERROR(const Args& ...args){
#ifdef ERROR_PRINT
        printerr_(Print(BG_RED),Print(FG_WHITE),Print(BOLD),args...,Print(DEFAULT)); 
#else
        UNUSED(args...);           
#endif
    }
    template <class ...Args>
    void INFO_D(const Args& ...args){            
#ifdef INFO_DEBUG_PRINT
        INFO(args...);
#else
        UNUSED(args...);
#endif
    }
    template <class ...Args>
    void SUCCESS_D(const Args& ...args){
#ifdef SUCCESS_DEBUG_PRINT
        SUCCESS(args...);
#else
        UNUSED(args...);
#endif
    }
    template <class ...Args>
    void WARNING_D(const Args& ...args){
#ifdef WARNING_DEBUG_PRINT
        WARNING(args...);
#else
        UNUSED(args...);           
#endif
    }
    template <class ...Args>
    void ERROR_D(const Args& ...args){
#ifdef ERROR_DEBUG_PRINT
        ERROR(args...);
#else
        UNUSED(args...);           
#endif
    }
}
#endif