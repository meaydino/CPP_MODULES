#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== TEST 1: CREATING FORM ===" << std::endl;
    try
    {
        Form contract("Contract", false, 50, 25);
        std::cout << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Invalid Grade (0) ===" << std::endl;
    try
    {
        Form invalid("Invalid", false, 0, 50);
        std::cout << invalid << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Invalid Grade (151) ===" << std::endl;
    try
    {
        Form invalid("Invalid", false, 151, 50);
        std::cout << invalid << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Signing Successful ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        Form contract("Contract", false, 50, 25);
        std::cout << boss << std::endl;
        std::cout << contract << std::endl;
        boss.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Signing Failed ===" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 140);
        Form topSecret("TopSecret", false, 10, 5);
        std::cout << intern << std::endl;
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
