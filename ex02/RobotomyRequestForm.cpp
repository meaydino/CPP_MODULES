#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"



RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other),  _target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if(!getBeSigned())
		throw FormNotSignedException();
	if(executor.getGrade() > getExecute())
		throw GradeTooLowException();
	std::cout << "* DRILLING NOISES * Bzzzzz..." << std::endl;
	if(time(NULL) % 2 == 0)
		std::cout << _target << " has bees robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << "!" << std::endl;

}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
