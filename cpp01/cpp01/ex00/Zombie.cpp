#include "Zombie.hpp"

Zombie::Zombie(void):_zombieName("unnamed")
{
}
Zombie::Zombie(std::string name) : _zombieName(name)
{
}
Zombie::~Zombie(void)
{
	std::cout << _zombieName << " is destroyed" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << _zombieName  << " BraiiiiiiinnnzzzZ... " << std::endl;
}
