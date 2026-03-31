#include "AForm.hpp"

AForm::AForm(): name("default"), is_signed(false), sign_grade(150), exec_grade(150) 
{
}

AForm::AForm(int sg, int eg, int is, const std::string n): name(n), is_signed(is), sign_grade(sg), exec_grade(eg)
{
    if (sg > 150 || eg > 150)
        throw AForm::GradeTooLowException();
    if (sg < 1 || eg < 1)
        throw AForm::GradeTooHighException();
}

AForm::~AForm(){}

AForm::AForm(const AForm &obj): name(obj.name), is_signed(obj.is_signed), sign_grade(obj.sign_grade), exec_grade(obj.exec_grade)
{
    if (obj.sign_grade > 150 || obj.exec_grade > 150)
        throw AForm::GradeTooLowException();
    if (obj.sign_grade < 1 || obj.exec_grade < 1)
        throw AForm::GradeTooHighException();
}

AForm &AForm::operator=(const AForm &obj)
{
    if (obj.sign_grade > 150 || obj.exec_grade > 150)
        throw AForm::GradeTooLowException();
    if (obj.sign_grade < 1 || obj.exec_grade < 1)
        throw AForm::GradeTooHighException();
    is_signed = obj.is_signed;
    return *this;
}

const std::string& AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return is_signed; }
int AForm::getSignGrade() const { return sign_grade; }
int AForm::getExecGrade() const { return exec_grade; }

void AForm::beSigned(Bureaucrat &obj)
{
    if (sign_grade < obj.getGrade())
        throw AForm::GradeTooLowException();
    is_signed = true;
}