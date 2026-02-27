#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        const std::string target;
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &obj);
        const PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
        void execute(Bureaucrat const & executor) const;
};
