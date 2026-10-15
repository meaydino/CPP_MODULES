#include "Harl.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

int main()
{
    Harl harl;
    
    std::cout << CYAN << "=== HARL COMPLAINT SYSTEM ===" << RESET << std::endl;
    std::cout << std::endl;

    std::cout << GREEN << "Testing DEBUG:" << RESET << std::endl;
    harl.complain("DEBUG");
    
    std::cout << BLUE << "Testing INFO:" << RESET << std::endl;
    harl.complain("INFO");
    
    std::cout << YELLOW << "Testing WARNING:" << RESET << std::endl;
    harl.complain("WARNING");
    
    std::cout << RED << "Testing ERROR:" << RESET << std::endl;
    harl.complain("ERROR");
    
    std::cout << MAGENTA << "Testing INVALID:" << RESET << std::endl;
    harl.complain("INVALID");
    
    std::cout << CYAN << "=== TESTING CASE SENSITIVITY ===" << RESET << std::endl;
    std::cout << MAGENTA << "Testing lowercase:" << RESET << std::endl;
    harl.complain("debug");
    std::cout << MAGENTA << "Testing mixed case:" << RESET << std::endl;
    harl.complain("Info");
    
    std::cout << CYAN << "=== INTERACTIVE TEST ===" << RESET << std::endl;
    std::cout << "Enter complaint level (" 
              << GREEN << "DEBUG" << RESET << "/" 
              << BLUE << "INFO" << RESET << "/" 
              << YELLOW << "WARNING" << RESET << "/" 
              << RED << "ERROR" << RESET << ") or 'quit': ";
    
    std::string input;
    while (std::cin >> input && input != "quit")
    {
        if (input == "DEBUG")
            std::cout << GREEN << ">> " << RESET;
        else if (input == "INFO")
            std::cout << BLUE << ">> " << RESET;
        else if (input == "WARNING")
            std::cout << YELLOW << ">> " << RESET;
        else if (input == "ERROR")
            std::cout << RED << ">> " << RESET;
        else
            std::cout << MAGENTA << ">> " << RESET;
            
        harl.complain(input);
        
        std::cout << "Enter complaint level (" 
                  << GREEN << "DEBUG" << RESET << "/" 
                  << BLUE << "INFO" << RESET << "/" 
                  << YELLOW << "WARNING" << RESET << "/" 
                  << RED << "ERROR" << RESET << ") or 'quit': ";
    }
    
    std::cout << CYAN << "Goodbye!" << RESET << std::endl;
    return 0;
}