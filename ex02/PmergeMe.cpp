#include "PmergeMe.hpp"
#include <sstream>
#include <limits>
#include <iostream>

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &other): _vector(other._vector) , _deque(other._deque)
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if(this != &other)
	{
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return(*this);
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parseInput(int ac, char **av)
{
	for(int i = 1;i < ac;i++)
	{
		std::stringstream ss(av[i]);
		long value;
		ss >> value;
		if(ss.fail() || !ss.eof())
			return(false);
		if(value < 0)
			return(false);
		if(value > std::numeric_limits<int>::max())
			return(false);

		_vector.push_back(static_cast<int>(value));
		_deque.push_back(static_cast<int>(value));
	}
	return(true);
}

void PmergeMe::sort()
{
	std::cout << "Before: ";

	for(int i = 0;i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}
