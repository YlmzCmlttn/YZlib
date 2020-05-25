#include "Core/Assert.hpp"
namespace YZlib{
    void YZ_assert(const bool& _condition,const char* err_msg){
#if defined(YZ_ASSERT)||defined(DEBUG)
        if(!_condition){
            ERROR("YZ_assert :",err_msg);
            assert(_condition);
        }
#else
        UNUSED(_condition,err_msg);
#endif
    }
}