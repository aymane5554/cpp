#include "Span.hpp"

Span::Span()
{
    arr = new int[0]();
    size = 0;
    length = 0;
}

Span::Span(size_t N)
{
    arr = new int[N]();
    size = N;
    length = 0;
}

Span::Span(const Span &copy)
{
    arr = new int[copy.size]();
    size = copy.size;
    length = copy.length;
    for (size_t i = 0; i < copy.length; i++)
    {
        arr[i] = copy.arr[i];
    }
}

Span &Span::operator=(const Span &copy)
{
    int *tmp = new int[copy.size]();
    delete arr;
    arr = tmp;
    size = copy.size;
    length = copy.length;
    for (size_t i = 0; i < copy.length; i++)
    {
        arr[i] = copy.arr[i];
    }
    return *this;
}

Span::~Span()
{
    delete arr;
}

void Span::addNumber(int num)
{
    if (length >= size)
        throw std::out_of_range("No Space Left");
    arr[length] = num;
    length++;
}
    
int Span::longestSpan() const
{
    int max;
    int min;

    if (length < 2)
        throw std::runtime_error("not enough numbers");
    max = *std::max_element(arr, arr + length);
    min = *std::min_element(arr, arr + length);

    return (max - min);
}

int Span::shortestSpan() const 
{
    if (length < 2)
        throw std::runtime_error("not enough numbers");
    Span copy(*this);
    std::sort(copy.arr, copy.arr + copy.length);

    int shortest = 2147483647;
    for (size_t i = 1; i < copy.length; i++)
    {
        if (arr[i - 1 ] > arr[i])
        {
            if  (arr[i - 1] - arr[i] < shortest)
                shortest = arr[i - 1] - arr[i];
        }
        else if (arr[i - 1] < arr[i])
        {
            if  (arr[i] - arr[i - 1] < shortest)
                shortest = arr[i] - arr[i - 1];
        }
    }
    return shortest;
}
