#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream& os, Bureaucrat &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}

std::ostream &operator<<(std::ostream& os, AForm &obj)
{
    os << obj.getName() << ", sign grade " << obj.getSignGrade() << ", execute grade " << obj.getExecGrade() << ", is Signed " << obj.getIsSigned();
    return os;
}

int main()
{
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        delete rrf;
        rrf = someRandomIntern.makeForm("wrong form", "home");
        std::cout << *rrf << std::endl;
        delete rrf;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
