#include "Bureaucrat.hpp"

int main()
{
    // TEST 1: Geçersiz grade (1000)
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

    // TEST 2: Geçerli grade (50)
    std::cout << "\n=== TEST 2: Grade 50 ===" << std::endl;
    try
    {
        Bureaucrat veli("veli", 50);
        std::cout << veli << std::endl;  // Bu çalışır!
    }
    catch(std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // TEST 3: Grade 0 (çok yüksek)
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
