#pragma once
#ifndef YZLIB_H
#define YZLIB_H
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    //define something for Windows (32-bit and 64-bit, this part is common)
        #define WIN_OS
    #ifdef _WIN64
        #define WIN64_OS
        //define something for Windows (64-bit only)
    #else
        #define WIN32_OS
        //define something for Windows (32-bit only)
    #endif
#elif __APPLE__
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR
        // iOS Simulator
        #define IPHONE_SIMILATOR_OS
    #elif TARGET_OS_IPHONE
        // iOS device
        #define IPHONE_OS
    #elif TARGET_OS_MAC
        #define MAC_OS
        // Other kinds of Mac OS
    #else
    #   error "Unknown Apple platform"
    #endif
#elif __linux__
    #define LINUX_OS
    // linux
#elif __unix__ // all unices not caught above
    #define UNIX_OS
    // Unix
#elif defined(_POSIX_VERSION)
    #define POSIX_OS
    // POSIX
#else
#   error "Unknown compiler"
#endif
#include <iostream>
#include <stdio.h>
#define LOG(x) std::cout<<x<<std::endl
namespace YZlib{
    void print_version();
}
#endif