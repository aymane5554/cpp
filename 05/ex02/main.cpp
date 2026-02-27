#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
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
        Bureaucrat b1(1, "Alice");
        Bureaucrat b2(150, "Bob");
        ShrubberyCreationForm f1("home");
        RobotomyRequestForm f2("Bender");
        PresidentialPardonForm f3("Charlie");

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;

        b1.signForm(f1);
        b1.signForm(f2);
        b1.signForm(f3);

        b1.executeForm(f1);
        b1.executeForm(f2);
        b1.executeForm(f3);

        b2.signForm(f1);
        b2.executeForm(f1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}