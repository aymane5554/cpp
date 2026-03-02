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
    arr = new int[copy.size];
    size = copy.size;
    length = copy.length;
    for (size_t i = 0; i < copy.length; i++)
    {
        arr[i] = copy.arr[i];
    }
}

Span &Span::operator=(const Span &copy)
{
    int *tmp = new int[copy.size];
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

void Span::addNumbers(int num[], size_t N)
{
    for (size_t i = 0; i < N; i++)
    {
        if (length >= size)
            throw std::out_of_range("No Space Left");
        arr[length] = num[i];
        length++;
    }
}

void Span::addNumber(int num)
{
    if (length >= size)
        throw std::out_of_range("No Space Left");
    arr[length] = num;
    length++;
}

int Span::shortestSpan() const
{
    return (0);
}
int Span::longestSpan() const
{

    return (0);
}
