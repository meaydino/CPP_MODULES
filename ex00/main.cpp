#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap1("Robot1");
    ClapTrap clap2("Robot2");
    
    std::cout << "\n--- Testing Attack ---" << std::endl;
    clap1.attack("Enemy");
    clap1.attack("Another Enemy");
    
    std::cout << "\n--- Testing Take Damage ---" << std::endl;
    clap1.takeDamage(5);
    clap1.takeDamage(3);
    clap1.takeDamage(10);
    
    std::cout << "\n--- Testing Repair ---" << std::endl;
    clap2.beRepaired(5);
    clap2.takeDamage(8);
    clap2.beRepaired(3);
    
    std::cout << "\n--- Testing Energy Depletion ---" << std::endl;
    ClapTrap clap3("EnergyTest");
    for (int i = 0; i < 12; i++)
    {
        clap3.attack("Target");
    }
    
    std::cout << "\n--- End of tests ---" << std::endl;
    return 0;
}