#include "Bureaucrat.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream& os, Bureaucrat &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}

std::ostream &operator<<(std::ostream& os, Form &obj)
{
    os << obj.getName() << ", sign grade " << obj.getSignGrade() << ", execute grade " << obj.getExecGrade() << ", is Signed " << obj.getIsSigned();
    return os;
}

int main()
{
    try
    {
        Bureaucrat b1(2, "name");
        std::cout << b1 << std::endl;
        Form f(1, 1, false, "form");
        b1.signForm(f);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}