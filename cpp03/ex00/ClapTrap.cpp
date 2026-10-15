#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) : name(name) , hitPoints(10), energyPoints(10) ,attackDamage(0)
{
    std::cout << "ClapTrap " << name << " is constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name) ,hitPoints(other.hitPoints) , energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap " << name << " is copy constructed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap " << name << " is assigned" << std::endl;
    if(this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << "is destructed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy points left and cannot attack!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
        return;
    }
    if (amount >= hitPoints)
    {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and dies!" << std::endl;
    }
    else
    {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Hit points: " << hitPoints << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is dead and cannot be repaired!" << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy points left and cannot be repaired!" << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points! Hit points: " << hitPoints << std::endl;
}
