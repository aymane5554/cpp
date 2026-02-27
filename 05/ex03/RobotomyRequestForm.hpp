#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        const std::string target;
    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &obj);
        const RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
        void execute(Bureaucrat const & executor) const;
};