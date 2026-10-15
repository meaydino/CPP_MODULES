#include <iostream>
#include "Array.hpp"

int main()
{
    std::cout << "========== TEST 1 : INT ARRAY ==========\n";

    Array<int> a(5);

    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i * 10;
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << "a[" << i << "] = " << a[i] << std::endl;



    std::cout << "\n========== TEST 2 : COPY CONSTRUCTOR ==========\n";

    Array<int> copy(a);

    a[0] = 999;

    std::cout << "Original changed:\n";
    std::cout << "a[0]    = " << a[0] << std::endl;
    std::cout << "copy[0] = " << copy[0] << " (should stay 0)\n";



    std::cout << "\n========== TEST 3 : ASSIGNMENT OPERATOR ==========\n";

    Array<int> assigned;
    assigned = a;

    a[1] = 777;

    std::cout << "Original changed:\n";
    std::cout << "a[1]       = " << a[1] << std::endl;
    std::cout << "assigned[1]= " << assigned[1] << " (should stay 10)\n";



    std::cout << "\n========== TEST 4 : OUT OF BOUNDS ==========\n";

    try
    {
        std::cout << a[42] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "\n========== TEST 5 : EMPTY ARRAY ==========\n";

    Array<int> empty;

    std::cout << "empty size = " << empty.size() << std::endl;
    try
    {
        empty[0] = 5;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception on empty array: " << e.what() << std::endl;
    }
    std::cout << "\n========== TEST 6 : STRING ARRAY ==========\n";

    Array<std::string> words(3);

    words[0] = "Hello";
    words[1] = "Template";
    words[2] = "World";

    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << words[i] << std::endl;
    std::cout << "\n========== ALL TESTS PASSED ==========\n";

    return 0;
}
