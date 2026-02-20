#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("EMPTY"), _grade(0)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if(grade < 1)
		throw GradeTooHighException();
	else if(grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name),
	_grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName() const
{
	return(this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}
