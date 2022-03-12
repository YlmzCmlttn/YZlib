#ifndef YZ_THREAD_FUNCTION_H
#define YZ_THREAD_FUNCTION_H
    #ifndef NUM_OF_THREAD
    #include <thread>
    #define NUM_OF_THREAD std::thread::hardware_concurrency()
    #endif
#include <iostream>
#include <vector>
#include <thread>
#include <functional>
namespace YZlib{    
    uint index_of_thread(const uint& size,const uint& num_of_thread);

    template<typename T_ret,typename... T_arrays>
    void function_wrapper_b(const std::function<T_ret(T_arrays...)>& _func,
                            const uint& iter,const uint& size,
                            const uint& id,
                            T_ret* ret,
                            const T_arrays* ...arrays,
                            T_arrays ...inputs)
    {
        uint _index=0;
        for(uint i=0;i<iter;i++){
            _index = (iter*id)+i;
            if(_index<size){
                ret[_index]=_func(arrays[_index]...,inputs...);
            }            
        }        
    }

    template<typename T_ret,typename... T_arrays>
    void function_wrapper_p(const std::function<T_ret(T_arrays...)>& _func,
                            const uint& iter,const uint& size,
                            const uint& id,
                            T_ret* ret,
                            const T_arrays* ...arrays)
    {
        uint _index=0;
        for(uint i=0;i<iter;i++){
            _index = (iter*id)+i;
            if(_index<size){
                ret[_index]=_func(arrays[_index]...);
            }            
        }        
    }

    template<typename T_ret,typename... T_arrays>
    void function_wrapper(const std::function<T_ret(T_arrays...)>& _func,
                            const uint& iter,const uint& size,
                            const uint& id,
                            T_ret* ret,
                            T_arrays ...inputs)
    {
        uint _index=0;
        for(uint i=0;i<iter;i++){
            _index = (iter*id)+i;
            if(_index<size){
                ret[_index]=_func(inputs...);
            }            
        }        
    }

    template<typename T_ret,typename... T_arrays>
    void thread_wrapper(const std::function<T_ret(T_arrays...)>& _func,                        
                        const uint& size, 
                        const uint& number_of_threads,
                        std::unique_ptr<T_ret>& ret,
                        std::unique_ptr<T_arrays>& ...arrays,
                        T_arrays ...inputs)
    {
        std::vector<std::thread> thread_pool;
        uint _iter = index_of_thread(size,number_of_threads);
        for(uint id=0;id<number_of_threads;id++){
            thread_pool.push_back(std::thread(function_wrapper_b<T_ret,T_arrays...>,_func,_iter,size,id,ret,arrays...,inputs...));
        }
        std::for_each(thread_pool.begin(), thread_pool.end(),[](std::thread &t){
            t.join();
        });
    }
    template<typename T_ret,typename... T_arrays>
    void thread_wrapper(const std::function<T_ret(T_arrays...)>& _func,                        
                        const uint& size, 
                        const uint& number_of_threads,
                        T_ret* ret,
                        const T_arrays* ...arrays)
    {
        std::vector<std::thread> thread_pool;
        uint _iter = index_of_thread(size,number_of_threads);
        for(uint id=0;id<number_of_threads;id++){
            thread_pool.push_back(std::thread(function_wrapper_p<T_ret,T_arrays...>,_func,_iter,size,id,ret,arrays...));
        }
        std::for_each(thread_pool.begin(), thread_pool.end(),[](std::thread &t){
            t.join();
        });
    }
    template<typename T_ret,typename... T_arrays>
    void thread_wrapper(const std::function<T_ret(T_arrays...)>& _func,                        
                        const uint& size, 
                        const uint& number_of_threads,
                        T_ret* ret,
                        T_arrays ...inputs)
    {
        std::vector<std::thread> thread_pool;
        uint _iter = index_of_thread(size,number_of_threads);
        for(uint id=0;id<number_of_threads;id++){
            thread_pool.push_back(std::thread(function_wrapper<T_ret,T_arrays...>,_func,_iter,size,id,ret,inputs...));
        }
        std::for_each(thread_pool.begin(), thread_pool.end(),[](std::thread &t){
            t.join();
        });
    }
}
#endif