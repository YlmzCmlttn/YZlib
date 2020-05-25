#include "Core/Print.h"
namespace YZlib{
    Print::Print(Code pCode):code(pCode){}
    std::ostream& operator<<(std::ostream& os, const Print& mod){
        return os << "\033[" << mod.code << "m";
    }
}