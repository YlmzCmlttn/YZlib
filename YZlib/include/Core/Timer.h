#ifndef TIMER_H
#define TIMER_H
#include <string.h>
#include <chrono>
#include <thread>
#include <iostream>
using namespace std::literals::chrono_literals;
namespace YZlib{
    class Timer
    {
    private:
        std::string message;
        std::chrono::time_point<std::chrono::system_clock> start,end;
        std::chrono::duration<double> duration;
    public:
        Timer();
        Timer(std::string _message);
        ~Timer();
    };
}
#endif