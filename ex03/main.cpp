#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;
    AForm* form;

    std::cout << "=== TEST 1: Shrubbery Creation ===" << std::endl;
    try
    {
        form = intern.makeForm("shrubbery creation", "home");
        if (form)
        {
            std::cout << *form << std::endl;
            delete form;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Robotomy Request ===" << std::endl;
    try
    {
        form = intern.makeForm("robotomy request", "Bender");
        if (form)
        {
            std::cout << *form << std::endl;
            delete form;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Presidential Pardon ===" << std::endl;
    try
    {
        form = intern.makeForm("presidential pardon", "Criminal");
        if (form)
        {
            std::cout << *form << std::endl;
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
        form = intern.makeForm("invalid form", "target");
        if (form)
            delete form;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Full Workflow ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 150);
        form = intern.makeForm("robotomy request", "Alice");
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

    return 0;
}
