#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other),  _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getBeSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecute())
        throw GradeTooLowException();

    std::ofstream file((_target + "_shrubbery").c_str());
    if (file.is_open())
    {
        file << "         v" << std::endl;
        file << "        >X<" << std::endl;
        file << "         A" << std::endl;
        file << "        d$b" << std::endl;
        file << "      .d\\$$b." << std::endl;
        file << "    .d$i$$\\$$b." << std::endl;
        file << "       d$$@b" << std::endl;
        file << "      d\\$$$ib" << std::endl;
        file << "    .d$$$\\$$$b" << std::endl;
        file << "  .d$$@$$$$\\$$ib." << std::endl;
        file << "      d$$i$$b" << std::endl;
        file << "     d\\$$$$@$b" << std::endl;
        file << "  .d$@$$\\$$$$$@b." << std::endl;
        file << ".d$$$$i$$$\\$$$$$$b." << std::endl;
        file << "        ###" << std::endl;
        file << "        ###" << std::endl;
        file << "        ###" << std::endl;
        file << std::endl;
        file.close();
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

