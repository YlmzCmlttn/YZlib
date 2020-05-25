#ifndef YZ_PRINT_H
#define YZ_PRINT_H
#include <iostream>
#include <string>
namespace YZlib{
    enum Code {
        FG_BLACK        = 30,
        FG_RED          = 31,
        FG_GREEN        = 32,
        FG_YELLOW       = 33,
        FG_BLUE         = 34,
        FG_MAGENTA      = 35,
        FG_CYAN         = 36,
        FG_WHITE        = 37,
        BG_BLACK        = 40,
        BG_RED          = 41,
        BG_GREEN        = 42,
        BG_YELLOW       = 43,
        BG_BLUE         = 44,
        BG_MAGENTA      = 45,
        BG_CYAN         = 46,
        BG_WHITE        = 47,
        DEFAULT         = 0,
        BOLD            = 1,
        UNDERLINE       = 4,
        INVERSE         = 7,
        BOLD_OFF        = 21,
        UNDERLINE_OFF   = 24,
        INVERSE_OFF     = 27
    };
    class Print {
        const Code code;
    public:
        Print()=delete;
        Print(const Code pCode);
        friend std::ostream& operator<<(std::ostream& os, const Print& mod);
    };
}
#endif