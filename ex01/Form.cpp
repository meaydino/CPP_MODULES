#include "Form.hpp"
#include"Bureaucrat.hpp"

Form::Form() : _name("EMPTY"), _beSigned(false), _grade(150), _execute(150)
{
}

Form::Form(const std::string &name, bool beSigned, int grade,
	int execute) : _name(name), _beSigned(beSigned), _grade(grade),
	_execute(execute)
{
	if (grade < 1 || _execute < 1)
		throw GradeTooHighException();
	else if (grade > 150 || _execute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _beSigned(other._beSigned),
	_grade(other._grade), _execute(other._execute)
{
}
Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_beSigned = other._beSigned;
	}
	return (*this);
}
const std::string &Form::getName() const
{
	return(_name);
}
bool Form::getBeSigned() const
{
	return (_beSigned);
}
int Form::getGrade() const
{
	return (_grade);
}
int Form::getExecute() const
{
	return (_execute);
}
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() > _grade)
		throw GradeTooLowException();
	_beSigned = true;
}
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}
const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}
Form::~Form()
{
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form: " << form.getName() << ", Signed: " << (form.getBeSigned() ? "Yes" : "No") << ", Grade to sign: " << form.getGrade() << ", Grade to execute: " << form.getExecute();
	return(os);
}
