#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>

class Span
{
    private:
        int *arr;
        size_t size;
        size_t length;
    public:
        Span();
        Span(size_t N);
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        ~Span();
        int shortestSpan() const;
        int longestSpan() const;
        void addNumber(int num);
        template <typename I>
        void addNumbers(I begin, I end)
        {
            I it;
            for (it = begin; it != end; it++)
            {
                if (length >= size)
                    throw std::out_of_range("Span is Full");
                arr[length] = *it;
                length++;
            }
        }

};
