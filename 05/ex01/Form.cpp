#include "Form.hpp"

Form::Form(): name("default"), is_signed(false), sign_grade(150), exec_grade(150) 
{
}

Form::Form(int sg, int eg, int is, const std::string n): name(n), is_signed(is), sign_grade(sg), exec_grade(eg)
{
    if (sg > 150 || eg > 150)
        throw Form::GradeTooLowException();
    if (sg < 1 || eg < 1)
        throw Form::GradeTooHighException();
}

Form::~Form(){}

Form::Form(const Form &obj): name(obj.name), is_signed(obj.is_signed), sign_grade(obj.sign_grade), exec_grade(obj.exec_grade)
{
    if (obj.sign_grade > 150 || obj.exec_grade > 150)
        throw Form::GradeTooLowException();
    if (obj.sign_grade < 1 || obj.exec_grade < 1)
        throw Form::GradeTooHighException();
}

Form &Form::operator=(const Form &obj)
{
    if (obj.sign_grade > 150 || obj.exec_grade > 150)
        throw Form::GradeTooLowException();
    if (obj.sign_grade < 1 || obj.exec_grade < 1)
        throw Form::GradeTooHighException();
    is_signed = obj.is_signed;
    return *this;
}

const std::string& Form::getName() const { return name; }
bool Form::getIsSigned() const { return is_signed; }
int Form::getSignGrade() const { return sign_grade; }
int Form::getExecGrade() const { return exec_grade; }

void Form::beSigned(Bureaucrat &obj)
{
    if (sign_grade < obj.getGrade())
        throw Form::GradeTooLowException();
    is_signed = true;
}