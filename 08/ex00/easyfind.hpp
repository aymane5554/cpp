#pragma once
#include <stdexcept>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw std::runtime_error("Target not found");
    }
    return it;
}
