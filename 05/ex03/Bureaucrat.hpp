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
                GradeTooHighException(): msg("Grade Too High\n") {};
                ~GradeTooHighException() throw() {};
                virtual const char *what() const throw()
                {
                    return msg.c_str();
                }
        };
        class GradeTooLowException : public std::exception
        {
            private:
                std::string msg;
            public:
                GradeTooLowException(): msg("Grade Too Low\n") {};
                ~GradeTooLowException() throw() {};
                virtual const char *what() const throw()
                {
                    return msg.c_str();
                }
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