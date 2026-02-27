#pragma once
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool is_signed;
        const int sign_grade;
        const int exec_grade;
    public:
        AForm();
        virtual ~AForm();
        AForm(int sg, int eg, int is, const std::string n);
        AForm(const AForm &obj);
        const AForm &operator=(const AForm &obj);
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
        const std::string& getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(Bureaucrat &obj);
        virtual void execute(Bureaucrat const & executor) const = 0;
};
