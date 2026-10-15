#include "AForm.hpp"
#include"Bureaucrat.hpp"

AForm::AForm() : _name("EMPTY"), _beSigned(false), _grade(150), _execute(150)
{
}

AForm::AForm(const std::string &name, int grade,
	int execute) : _name(name), _beSigned(false), _grade(grade),
	_execute(execute)
{
	if (grade < 1 || _execute < 1)
		throw GradeTooHighException();
	else if (grade > 150 || _execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _beSigned(other._beSigned),
	_grade(other._grade), _execute(other._execute)
{
}
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_beSigned = other._beSigned;
	}
	return (*this);
}
const std::string &AForm::getName() const
{
	return(_name);
}
bool AForm::getBeSigned() const
{
	return (_beSigned);
}
int AForm::getGrade() const
{
	return (_grade);
}
int AForm::getExecute() const
{
	return (_execute);
}
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() > _grade)
		throw GradeTooLowException();
	_beSigned = true;
}
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}
const char *AForm::FormNotSignedException::what() const throw()
{
	return("Form is not signed!");
}
AForm::~AForm()
{
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "AForm: " << form.getName() << ", Signed: " << (form.getBeSigned() ? "Yes" : "No") << ", Grade to sign: " << form.getGrade() << ", Grade to execute: " << form.getExecute();
	return(os);
}
