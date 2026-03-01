#pragma once
#include <cstdlib>
#include <iostream>

template <typename T, typename F>
void iter(T *array, const size_t size, F func)
{
    for (size_t i = 0; i < size; i++)
        func(array[i]);
}

template <typename T>
void print(T &arg)
{
    std::cout << arg << " ";
}
