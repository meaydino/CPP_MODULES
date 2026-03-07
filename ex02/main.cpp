#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "=== TEST 1: Shrubbery ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub("home");
        boss.signForm(shrub);
        boss.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Robotomy ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robot("Bender");
        boss.signForm(robot);
        boss.executeForm(robot);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Presidential ===" << std::endl;
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Criminal");
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Unsigned Form ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub("garden");
        boss.executeForm(shrub); // imzasız!
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Grade Too Low ===" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm pardon("Someone");
        intern.signForm(pardon); // grade yetersiz!
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
