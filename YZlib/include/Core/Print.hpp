#ifndef YZ_PRINT_HPP
#define YZ_PRINT_HPP
#include <iostream>
#include <mutex>
#include "Core/Print.h"
namespace YZlib{
    inline std::ostream& print_one(std::ostream& os)
    {
        return os;
    }
    template <class A0, class ...Args>        
    std::ostream& print_one(std::ostream& os, const A0& a0, const Args& ...args)
    {
        os << a0;
        return print_one(os, args...);
    }
    template <class ...Args>
    std::ostream& print(std::ostream& os, const Args& ...args)
    {
        return print_one(os, args...);
    }
    static std::mutex& get_cout_mutex()
    {
        static std::mutex m;
        return m;
    }
    template <class ...Args>
    std::ostream& print(const Args& ...args)
    {
        std::lock_guard<std::mutex> lck(get_cout_mutex());
        return print(std::cout, args...);
    }        
    template <class ...Args>
    std::ostream& printerr(const Args& ...args)
    {
        std::lock_guard<std::mutex> lck(get_cout_mutex());
        return print(std::cerr, args...);
    }
    template <class ...Args>
    std::ostream& print_(const Args& ...args)
    {
        std::lock_guard<std::mutex> lck(get_cout_mutex());
        return print(std::cout, args...)<<std::endl;
    }        
    template <class ...Args>
    std::ostream& printerr_(const Args& ...args)
    {
        std::lock_guard<std::mutex> lck(get_cout_mutex());
        return print(std::cerr, args...)<<std::endl;
    }
    static inline void YZ_printf(const char* format)
    {
        std::cout << format;
    }
    template<typename T, typename... Targs>
    void YZ_printf(const char* format, T value, Targs... Fargs)
    {
        for ( ;*format != '\0'; format++ ){
            if ( *format == '{' ) {
                format++;
                if ( *format == 'y' ) {
                    format++;
                    if ( *format == 'z' ) {
                        format++;
                        if ( *format == '}' ) {
                            std::cout << value;
                            YZ_printf(format+1, Fargs...);
                            return;
                        }else{format--;format--;format--;}
                    }else{format--;format--;}
                }else{format--;}
            }
            std::cout << *format;
        }
    }
}
#endif