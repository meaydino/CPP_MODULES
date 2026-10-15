#include "Zombie.hpp"

Zombie::Zombie(void)
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
void Zombie::setName(std::string name)
{
	_zombieName = name;
	std::cout << "Zombie " << _zombieName << " created" << std::endl;
}
Zombie* zombieHorde( int N, std::string name )
{
	if(N <= 0)
		return(NULL);
	Zombie* horde = new Zombie[N];
	for(int i = 0; i < N; i++)
		horde[i].setName(name);
	return(horde);
}
