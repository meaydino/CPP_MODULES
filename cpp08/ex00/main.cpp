#include "easyfind.hpp"

#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
    std::vector<int> vec;

    vec.push_back(3);
    vec.push_back(7);
    vec.push_back(10);
    vec.push_back(15);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 10);

        std::cout << "Found : " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        easyfind(vec, 42);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}