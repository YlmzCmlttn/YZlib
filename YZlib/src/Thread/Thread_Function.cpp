#include "Thread/Thread_Function.hpp"
namespace YZlib{
    uint index_of_thread(const uint& size,const uint& num_of_thread){
        uint _iter=0;
        if((size%num_of_thread)==0){
            _iter = (size/num_of_thread);
        }else{
            _iter = (size/num_of_thread)+1;
        }
        return _iter;
        }
}