#include<iostream>
int main(int ac, char **av)
{
	if(ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	for(int i = 1; i < ac; i++)
	{
		for(int j = 0; av[i][j] != '\0'; j++)
			std::cout << (char)toupper(av[i][j]);
		if(i != ac - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}
