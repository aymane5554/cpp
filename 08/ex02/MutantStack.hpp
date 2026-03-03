#pragma once

#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
    public:
        class iterator
        {
            public:
                T *ptr;
                iterator ()
                {
                    ptr = 0;
                }
                ~iterator()
                {}
                iterator (const iterator &it)
                {
                    ptr = it.ptr;
                }
                iterator &operator=(const iterator& it)
                {
                    ptr = it.ptr;
                }
                T operator*()
                {
                    return *ptr;
                }
                bool operator!=(const iterator &it)
                {
                    return ptr != it.ptr;
                }
                bool operator==(const iterator &it)
                {
                    return ptr == it.ptr;
                }
                iterator &operator++()
                {
                    ptr--;
                    return *this;
                }
                iterator operator++(int)
                {
                    iterator tmp(*this);
                    ptr--;
                    return tmp;
                }
                iterator &operator--()
                {
                    ptr++;
                    return *this;
                }
                iterator operator--(int)
                {
                    iterator tmp(*this);
                    ptr++;
                    return tmp;
                }
        };
        MutantStack<T>::iterator begin()
        {
            iterator it;
            
            if (this->c.empty())
                it.ptr = 0;
            else
                it.ptr =  &this->c.back();
            return it;
        }
        MutantStack<T>::iterator end()
        {
            iterator it;
            
            if (this->c.empty())
                it.ptr = 0;
            else
                it.ptr =  &this->c.front();
            return it;
        }
};
