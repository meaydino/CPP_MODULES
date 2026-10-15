#include<iostream>
#include "FileReplacer.hpp"

int main(int ac, char **av)
{
    if(ac != 4)
    {
        std::cout << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
        return(1);
    }
    
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if(s1.empty())
    {
        std::cout << "Error: s1 cannot be empty" << std::endl;
        return(1);
    }
    
    // FileReplacer objesi oluştur ve çalıştır
    FileReplacer replacer(filename, s1, s2);
    if (!replacer.replaceInFile()) {
        std::cout << "Error: File replacement failed" << std::endl;
        return(1);
    }
    
    std::cout << "File replacement completed successfully" << std::endl;
    return(0);
}