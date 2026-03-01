#include "iter.hpp"

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, print<int>);
    std::cout << std::endl;

    char str[] = "Hello";
    iter(str, 5, print<char>);
    std::cout << std::endl;

    float farr[] = {1.1f, 2.2f, 3.3f};
    iter(farr, 3, print<float>);
    std::cout << std::endl;

    std::string sarr[] = {"Hello", "World", "!"};
    iter(sarr, 3, print<const std::string &>);
    std::cout << std::endl;
    return 0;
}
