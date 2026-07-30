#include <iostream>
#include "PmergeMe.hpp"


int main(int ac, char **av)
{
	if(ac < 2)
	{
		std::cout << "Error" << std::endl;
		return(1);
	}
	PmergeMe sorter;
	if(!sorter.parseInput(ac, av))
	{
		std::cout << "Error" << std::endl;
		return(1);
	}
	sorter.sort();
	return(0);



}
