#include "PmergeMe.hpp"
#include <sstream>
#include <limits>
#include <iostream>
#include<algorithm>

std::vector<int> PmergeMe::fordJohnson(std::vector<int> numbers)
{
	return std::vector<int>();
}

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other): _vector(other._vector) , _deque(other._deque), _pairs(other._pairs)
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if(this != &other)
	{
		this->_vector = other._vector;
		this->_deque = other._deque;
		this->_pairs = other._pairs;
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

	for(size_t i = 0;i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
	makePairs();
	splitPairs();
}

void PmergeMe::makePairs()
{
	_pairs.clear();
	    // i + 1 < size() diyerek son elemanın eşi var mı kontrol ediyoruz
	for(size_t i = 0; i + 1 < _vector.size(); i += 2)
	{
		int first = _vector[i];
		int second = _vector[i + 1];

		if(first > second)
			std::swap(first, second);
		_pairs.push_back(std::make_pair(first, second));
	}
	std::cout << "Pairs:" << std::endl;
	for(size_t i = 0;i < _pairs.size(); i++)
	{
		std::cout << "(" << _pairs[i].first << "," << _pairs[i].second << ")" << std::endl;
	}
}

void PmergeMe::splitPairs()
{
	_mainChain.clear();
	_pend.clear();

	for(size_t i = 0;i < _pairs.size();i++)
	{
		_pend.push_back(_pairs[i].first);
		_mainChain.push_back(_pairs[i].second);
	}
	std::cout << "\nMain Chain" << std::endl;
	for(size_t i = 0;i < _mainChain.size();i++)
		std::cout << _mainChain[i] << " ";

	std::cout << std::endl;
	std::cout << "\nPend:\n";

    for (size_t i = 0; i < _pend.size(); i++)
        std::cout << _pend[i] << " ";

    std::cout << std::endl;

}
