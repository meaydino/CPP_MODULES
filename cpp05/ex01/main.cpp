#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== TEST 1: CREATING FORM ===" << std::endl;
    try
    {
        Form contract("Contract", 50, 25);
        std::cout << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Invalid Grade (0) ===" << std::endl;
    try
    {
        Form invalid("Invalid", 0, 50);
        std::cout << invalid << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Invalid Grade (151) ===" << std::endl;
    try
    {
        Form invalid("Invalid", 151, 50);
        std::cout << invalid << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Sign Form Success ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        Form contract("Contract", 50, 25);
        std::cout << contract << std::endl;
        boss.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Sign Form Fail ===" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 150);
        Form topSecret("TopSecret", 10, 5);
        std::cout << topSecret << std::endl;
        intern.signForm(topSecret);
        std::cout << topSecret << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
