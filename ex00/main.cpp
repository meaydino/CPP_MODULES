#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== TEST 1: Grade 1000 ===" << std::endl;
    try
    {
        Bureaucrat ali("ali", 1000);
        std::cout << ali << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Grade 50 ===" << std::endl;
    try
    {
        Bureaucrat veli("veli", 50);
        std::cout << veli << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Grade 0 ===" << std::endl;
    try
    {
        Bureaucrat hasan("hasan", 0);
        std::cout << hasan << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
