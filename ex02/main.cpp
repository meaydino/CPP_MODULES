#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
    
    std::cout << BOLD << GREEN << "\n\n=== FragTrap Tests ===" << RESET << std::endl;
    FragTrap frag1("FR4G-TP");
    FragTrap frag2("Demolisher");
    
    std::cout << CYAN << "\n--- Testing FragTrap Attack (30 damage) ---" << RESET << std::endl;
    frag1.attack("Skag");
    frag1.attack("Rakk");
    
    std::cout << YELLOW << "\n--- Testing FragTrap Take Damage (100 HP) ---" << RESET << std::endl;
    frag1.takeDamage(40);
    frag1.takeDamage(35);
    frag1.takeDamage(30);
    
    std::cout << GREEN << "\n--- Testing FragTrap Repair ---" << RESET << std::endl;
    frag2.beRepaired(30);
    frag2.takeDamage(80);
    frag2.beRepaired(20);
    
    std::cout << BOLD << CYAN << "\n--- Testing FragTrap Special Ability ---" << RESET << std::endl;
    frag1.highFivesGuys();
    frag2.highFivesGuys();
    
    std::cout << RED << "\n--- Testing FragTrap Energy (100 points) ---" << RESET << std::endl;
    FragTrap fragEnergyTest("FragEnergyTester");
    std::cout << "Performing 50 attacks:" << std::endl;
    for (int i = 0; i < 52; i++)
    {
        if (i == 50)
            std::cout << "Attempting more attacks after 50..." << std::endl;
        fragEnergyTest.attack("Target");
    }
    
    std::cout << BOLD << WHITE << "\n--- Construction/Destruction Chain Test (FragTrap) ---" << RESET << std::endl;
    {
        std::cout << GREEN << "Creating temporary FragTrap:" << RESET << std::endl;
        FragTrap temp("TempFrag");
        temp.highFivesGuys();
        std::cout << RED << "Leaving scope - watch destruction order:" << RESET << std::endl;
    }
    
    std::cout << BOLD << CYAN << "\n--- Copy Constructor Test (FragTrap) ---" << RESET << std::endl;
    FragTrap original("Original");
    FragTrap copy(original);
    copy.highFivesGuys();
    
    std::cout << BOLD << GREEN << "\n--- Assignment Operator Test (FragTrap) ---" << RESET << std::endl;
    FragTrap assigned("Assigned");
    assigned = original;
    assigned.highFivesGuys();
    
    std::cout << BOLD << YELLOW << "\n--- Comparing All Three Types ---" << RESET << std::endl;
    std::cout << "ClapTrap: 10 HP, 10 Energy, 0 Damage" << std::endl;
    std::cout << "ScavTrap: 100 HP, 50 Energy, 20 Damage, Guard Gate" << std::endl;
    std::cout << "FragTrap: 100 HP, 100 Energy, 30 Damage, High Fives!" << std::endl;
    
    std::cout << BOLD << BLUE << "\n=== End of tests ===" << RESET << std::endl;
    return 0;
}