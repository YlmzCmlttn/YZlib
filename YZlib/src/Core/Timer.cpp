#include "Core/Timer.h"
#include "YZlib.h"
#include <sstream>
using namespace std::literals::chrono_literals;
namespace YZlib{     
    Timer::Timer():
        message("Unknown")
    {
#ifdef LINUX_OS
        start=std::chrono::high_resolution_clock::now();
#endif

#if defined(MAC_OS) || defined(WIN_OS)
        start=std::chrono::system_clock::now();
#endif
    }        
    Timer::Timer(std::string _message)
        :message(_message)
    {
#ifdef LINUX_OS
        start=std::chrono::high_resolution_clock::now();
#endif
#if defined(MAC_OS) || defined(WIN_OS)
        start=std::chrono::system_clock::now();
#endif
    }        
    Timer::~Timer()
    {
#ifdef LINUX_OS
        end=std::chrono::high_resolution_clock::now();
#endif
#if defined(MAC_OS) || defined(WIN_OS)
        end=std::chrono::system_clock::now();
#endif
        duration = end-start;
		std::stringstream ss;

        ss<< duration.count()*1000.0f;            
		std::string s;
		ss >> s;
		std::cout <<"Timer of "<<message<<" is "<< s <<" miliseconds."<< std::endl;
    }
}