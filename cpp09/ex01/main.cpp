#include<iostream>
#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    RPN rpn;

    try
    {
        int result = rpn.calculate(av[1]);
        std::cout << result << std::endl;
    }
    catch(...)
    {
        std::cerr << "Error" << std::endl;
    }
}
