#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

AForm *Intern::createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}
AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*formCreator[3])(const std::string&) = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};
	for(int i = 0; i < 3 ; i++)
	{
		if(formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return((this->*formCreator[i])(target));
		}
	}
	std::cout << "Intern couldn't create " << formName << " because form doesn't exist!" << std::endl;
	return(NULL);
}

Intern::~Intern()
{
}
