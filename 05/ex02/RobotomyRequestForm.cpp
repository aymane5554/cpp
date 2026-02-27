#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): AForm(72, 45, 0, "RobotomyRequestForm")
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm(72, 45, 0, "RobotomyRequestForm"), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm(copy), target(copy.target)
{
}

const RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    AForm::operator=(copy);
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
    {
        std::cerr << "The form is not signed." << std::endl;
        return ;
    }
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    srand(time(NULL));
    int random = rand() % 2;
    if (random == 0)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << target << " robotomization failed." << std::endl;
}
