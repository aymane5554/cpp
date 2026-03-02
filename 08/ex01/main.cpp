#include <iostream>
#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    int arr[] = {0, 2, 3};
    sp.addNumbers(arr, 3);
    sp.addNumber(2);
    sp.addNumber(2);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}
