#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &other);
        ~Intern();
        Intern &operator=(const Intern &other);
        AForm *makeForm(const std::string &formName, const std::string &target);
        class FormNotFoundException : public std::exception
        {
            private:
                std::string msg;
            public:
                FormNotFoundException() : msg("Form Not Found\n") {}
                ~FormNotFoundException() throw() {}
                virtual const char *what() const throw()    {
                    return msg.c_str();
                }
        };
};  