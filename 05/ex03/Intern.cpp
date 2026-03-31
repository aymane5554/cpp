#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            for (int j = 0; j < 3; j++)
            {
                if (j != i)
                    delete forms[j];
            }
            return forms[i];
        }
    }
    for (int i = 0; i < 3; i++)
        delete forms[i];
    throw FormNotFoundException();
}

Intern::FormNotFoundException::FormNotFoundException() : msg("Form Not Found\n") {}
Intern::FormNotFoundException::~FormNotFoundException() throw() {}
const char *Intern::FormNotFoundException::what() const throw()
{
    return msg.c_str();
}
