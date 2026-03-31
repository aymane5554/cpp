#pragma once
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int sign_grade;
        const int exec_grade;
    public:
        Form();
        ~Form();
        Form(int sg, int eg, int is, const std::string n);
        Form(const Form &obj);
        Form &operator=(const Form &obj);
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
        const std::string& getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(Bureaucrat &obj);
};
