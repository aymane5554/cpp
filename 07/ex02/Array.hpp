#pragma once

#include <cstdlib>
#include <exception>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T *arr;
        size_t _size;
    public:
        Array()
        {
            arr = new T[0]();
            _size = 0;
        }
        Array(unsigned int n)
        {
            arr = new T[n]();
            this->_size = n;
        }
        Array(Array<T> &copy)
        {
            arr = new T[copy._size]();
            for (size_t i = 0; i < copy._size; i++)
            {
                arr[i] = copy[i];
            }
            _size = copy._size;
        }
        Array &operator=(Array<T> &copy)
        {
            if (this != &copy)
            {
                T *tmp = new T[copy._size]();
                delete[] arr;
                arr = tmp;
                for (size_t i = 0; i < copy._size; i++)
                {
                    arr[i] = copy[i];
                }
                _size = copy._size;
            }
        }
        T &operator[](size_t index)
        {
            if (index >= _size)
            {
                throw std::out_of_range("Index out of bounds");
            }
            return arr[index];
        }
        ~Array()
        {
            delete[] arr;
        }
        size_t size() const
        {
            return _size;
        }
};
