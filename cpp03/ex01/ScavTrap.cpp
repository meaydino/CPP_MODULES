#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " is constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << name << " is copy constructed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap " << name << " is assigned!" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " is destructed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints == 0)
    {
        std::cout << "ScavTrap " << name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ScavTrap " << name << " has no energy points left and cannot attack!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}