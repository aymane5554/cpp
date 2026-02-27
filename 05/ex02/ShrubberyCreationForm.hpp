#pragma once
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm: public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm(const std::string &target);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
};