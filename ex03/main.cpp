#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "=== TEST 1: Intern Shrubbery ===" << std::endl;
    try
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        AForm* form = intern.makeForm("shrubbery creation", "home");
        if (form)
        {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Intern Robotomy ===" << std::endl;
    try
    {
        Intern intern;
        Bureaucrat boss("Boss", 150);
        AForm* form = intern.makeForm("robotomy request", "Bender");
        if (form)
        {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Intern Presidential ===" << std::endl;
    try
    {
        Intern intern;
        Bureaucrat president("President", 150);
        AForm* form = intern.makeForm("presidential pardon", "Criminal");
        if (form)
        {
            president.signForm(*form);
            president.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Invalid Form ===" << std::endl;
    try
    {
        Intern intern;
        AForm* form = intern.makeForm("invalid form", "target");
        if (form)
            delete form;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Grade Too Low ===" << std::endl;
    try
    {
        Intern intern;
        Bureaucrat lowGrade("Intern", 150);
        AForm* form = intern.makeForm("presidential pardon", "Someone");
        if (form)
        {
            lowGrade.signForm(*form);
            lowGrade.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
