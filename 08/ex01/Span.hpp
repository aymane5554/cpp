#pragma once
#include <iostream>
#include <stdexcept>

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
        void addNumbers(int num[], size_t N);
};