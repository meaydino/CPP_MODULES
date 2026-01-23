#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

// ANSI Color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

int main()
{
    std::cout << BOLD << BLUE << "=== ClapTrap Tests ===" << RESET << std::endl;
    ClapTrap clap1("Robot1");
    ClapTrap clap2("Robot2");
    
    std::cout << CYAN << "\n--- Testing ClapTrap Attack ---" << RESET << std::endl;
    clap1.attack("Enemy");
    clap1.attack("Another Enemy");
    
    std::cout << YELLOW << "\n--- Testing ClapTrap Take Damage ---" << RESET << std::endl;
    clap1.takeDamage(5);
    clap1.takeDamage(3);
    clap1.takeDamage(10);
    
    std::cout << GREEN << "\n--- Testing ClapTrap Repair ---" << RESET << std::endl;
    clap2.beRepaired(5);
    clap2.takeDamage(8);
    clap2.beRepaired(3);
    
    std::cout << RED << "\n--- Testing ClapTrap Energy Depletion ---" << RESET << std::endl;
    ClapTrap clap3("EnergyTest");
    for (int i = 0; i < 12; i++)
    {
        clap3.attack("Target");
    }
    
    std::cout << BOLD << MAGENTA << "\n\n=== ScavTrap Tests ===" << RESET << std::endl;
    ScavTrap scav1("SC4V-TP");
    ScavTrap scav2("Guardian");
    
    std::cout << CYAN << "\n--- Testing ScavTrap Attack ---" << RESET << std::endl;
    scav1.attack("Bandit");
    scav1.attack("Psycho");
    
    std::cout << YELLOW << "\n--- Testing ScavTrap Take Damage ---" << RESET << std::endl;
    scav1.takeDamage(30);
    scav1.takeDamage(50);
    scav1.takeDamage(25);
    
    std::cout << GREEN << "\n--- Testing ScavTrap Repair ---" << RESET << std::endl;
    scav2.beRepaired(25);
    scav2.takeDamage(70);
    scav2.beRepaired(15);
    
    std::cout << BOLD << YELLOW << "\n--- Testing ScavTrap Special Ability ---" << RESET << std::endl;
    scav1.guardGate();
    scav2.guardGate();
    
    std::cout << RED << "\n--- Testing ScavTrap Energy (50 points) ---" << RESET << std::endl;
    ScavTrap energyTest("EnergyTester");
    for (int i = 0; i < 52; i++)
    {
        energyTest.attack("Target");
    }
    
    std::cout << BOLD << WHITE << "\n--- Construction/Destruction Chain Test ---" << RESET << std::endl;
    {
        std::cout << GREEN << "Creating temporary ScavTrap:" << RESET << std::endl;
        ScavTrap temp("TempScav");
        temp.guardGate();
        std::cout << RED << "Leaving scope - watch destruction order:" << RESET << std::endl;
    }
    
    std::cout << BOLD << CYAN << "\n--- Copy Constructor Test ---" << RESET << std::endl;
    ScavTrap original("Original");
    ScavTrap copy(original);
    copy.guardGate();
    
    std::cout << BOLD << GREEN << "\n--- Assignment Operator Test ---" << RESET << std::endl;
    ScavTrap assigned("Assigned");
    assigned = original;
    assigned.guardGate();
    
    std::cout << BOLD << BLUE << "\n=== End of tests ===" << RESET << std::endl;
    return 0;
}