#ifndef YZ_RANDOM_HPP
#define YZ_RANDOM_HPP
    #if defined (_MSC_VER)  // Visual studio
        #define thread_local __declspec( thread )
    #elif defined (__GCC__) // GCC
        #define thread_local __thread
    #endif
#include <random>
#include <time.h>
#include <thread>
#include <iostream>
#include <assert.h>
#include <chrono>
#include <ctime>
namespace YZlib{
    template<class T>
    using uniform_distribution = 
    typename std::conditional<
        std::is_floating_point<T>::value,
        std::uniform_real_distribution<T>,
        typename std::conditional<
            std::is_integral<T>::value,
            std::uniform_int_distribution<T>,
            void
        >::type
    >::type;
    template <class T>
    T GetRand(T lower, T upper)
    {
        static thread_local std::mt19937_64 mt(std::random_device{}());
        uniform_distribution<T> dist(lower,upper);
        return dist(mt);
    }
    template <typename _Type> 
    _Type Rand(const _Type& min, const _Type& max){
        static thread_local std::mt19937* generator = nullptr;
        if (!generator) generator = new std::mt19937(std::clock() +std::hash<std::thread::id>()(std::this_thread::get_id()));
        std::uniform_real_distribution<_Type> distribution(min, max);
        return distribution(*generator);
    }
}
#endif