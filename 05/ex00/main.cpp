#include "Bureaucrat.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream& os, Bureaucrat &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}

int main()
{
    try
    {
        Bureaucrat b1(1, "name");
        std::cout << b1 << std::endl;
        Bureaucrat b(-1, "hello");
        b.dec();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}