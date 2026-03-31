#pragma once

#include <string>
#include <exception>
#include "AForm.hpp"
#include <iostream>

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        class GradeTooHighException : public std::exception
        {
            private:
                std::string msg;
            public:
                GradeTooHighException();
                ~GradeTooHighException() throw();
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            private:
                std::string msg;
            public:
                GradeTooLowException();
                ~GradeTooLowException() throw();
                virtual const char *what() const throw();
        };
        Bureaucrat();
        Bureaucrat(int g, const std::string &n);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void inc();
        void dec();
        void signForm(AForm &form);
        void executeForm(AForm const & form);
};