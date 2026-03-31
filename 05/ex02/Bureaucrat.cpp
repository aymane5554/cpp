#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
}

Bureaucrat::Bureaucrat(int g, const std::string &n): name(n)
{
    if (g < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (g > 150)
        throw Bureaucrat::GradeTooLowException();
    grade = g;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.name)
{
    if (obj.grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (obj.grade > 150)
        throw Bureaucrat::GradeTooLowException();
    grade = obj.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (obj.grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (obj.grade > 150)
        throw Bureaucrat::GradeTooLowException();
    grade = obj.grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{}

int Bureaucrat::getGrade() const
{
    return grade;
}

std::string Bureaucrat::getName() const
{
    return name;
}

void Bureaucrat::dec()
{
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

void Bureaucrat::inc()
{
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    }
    catch(const AForm::GradeTooLowException e)
    {
        std::cerr << getName() << "couldn’t sign " << form.getName() << " because " << e.what() << '\n';
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    }
    catch(const AForm::GradeTooLowException e)
    {
        std::cerr << getName() << " couldn’t execute " << form.getName() << " because " << e.what() << '\n';
    }
}

Bureaucrat::GradeTooHighException::GradeTooHighException(): msg("Grade Too High\n") {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
Bureaucrat::GradeTooLowException::GradeTooLowException(): msg("Grade Too Low\n") {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return msg.c_str();
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return msg.c_str();
}
