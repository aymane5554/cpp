#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
    std::vector<int> vec;
    for (int i = 1; i <= 5; i++)
    {
        vec.push_back(i);
    }
    try
    {
        easyfind(vec, 3);
        std::cout << "Value found in vector" << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    try
    {
        easyfind(myList, 30);
        std::cout << "Value found in list" << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
