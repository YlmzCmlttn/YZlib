#ifndef YZ_ITERATOR_HPP
#define YZ_ITERATOR_HPP
#include <iostream>
#include <cstdlib>
#include <cmath>
namespace YZlib{
    template<typename _T>
    class Iterator
    {
    public:
        typedef Iterator self_type;
        typedef _T value_type;
        typedef _T& reference;
        typedef _T* pointer;
        typedef std::forward_iterator_tag iterator_category;
        typedef int difference_type;
        Iterator(pointer ptr) : ptr_(ptr) { }
        self_type operator++() { self_type i = *this; ptr_++; return i; }
        self_type operator++(int junk) { ptr_+=junk; return *this; }
        reference operator*() { return *ptr_; }
        pointer operator->() { return ptr_; }
        bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
        bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
    private:
        pointer ptr_;
    };

    template<typename _T>
    class const_Iterator
    {
    public:
        typedef const_Iterator self_type;
        typedef _T value_type;
        typedef _T& reference;
        typedef _T* pointer;
        typedef int difference_type;
        typedef std::forward_iterator_tag iterator_category;
        const_Iterator(pointer ptr) : ptr_(ptr) { }
        self_type operator++() { self_type i = *this; ptr_++; return i; }
        self_type operator++(int junk) { ptr_+=junk; return *this; }
        reference operator*() { return *ptr_; }
        pointer operator->() { return ptr_; }
        bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
        bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
    private:
        pointer ptr_;
    };
}
#endif