#include "PmergeMe.hpp"
#include <sstream>
#include <limits>
#include <iostream>
#include<algorithm>


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
	std::vector<int> result;

    result = fordJohnson(_vector);


    std::cout << "\nSorted: ";

    for(size_t i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";

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
std::vector<size_t> PmergeMe::generateJacobsthalOrder(size_t size)
{
	//J(n)=J(n-1)+2*J(n-2)
	std::vector<size_t> order;

	std::vector<size_t> jacob;

	jacob.push_back(0);
	jacob.push_back(1);

	while(jacob.back() < size)
	{
		size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() -2];
		jacob.push_back(next);
	}
	size_t prev = 1;
	for(size_t i = 2;i < jacob.size();i++)
	{
		size_t curr = jacob[i];
		if(curr > size)
			curr = size;
		for(size_t j = curr; j > prev; j--)
			order.push_back(j - 1);
		prev = jacob[i];
	}
	return(order);
}
void PmergeMe::insertPend(std::vector<int> &main, std::vector<int> &pend)
{
	std::vector<size_t> order;
	order = generateJacobsthalOrder(pend.size());
	for(size_t i = 0;i < order.size(); i++)
	{
		size_t index = order[i];
		int value = pend[index];
		std::vector<int>::iterator pos;
		pos = std::lower_bound(main.begin(), main.end(), value);
		main.insert(pos, value);
	}
}
std::vector<int> PmergeMe::fordJohnson(std::vector<int> numbers)
{
	if(numbers.size() <= 1)
		return(numbers);
	std::cout << "\nRecursive input: ";

	for(size_t i = 0;i < numbers.size();i++)
		std::cout << numbers[i] << " ";

	std::cout << std::endl;

	std::vector<std::pair<int, int> > pairs;
	int leftover = -1;
	bool hasleftover= false;

	for(size_t i = 0;i + 1 < numbers.size(); i += 2)
	{
		int first = numbers[i];
		int second = numbers[i + 1];

		if(first > second)
			std::swap(first, second);

		pairs.push_back(std::make_pair(first,second));
	}
	if(numbers.size() % 2 != 0)
	{
		leftover = numbers.back();
		hasleftover = true;
	}

	std::cout << "Pairs:\n";
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::cout << "(" << pairs[i].first<< ","<< pairs[i].second<< ")"<< std::endl;
    }

	std::vector<int> big;
	std::vector<int> small;

	for(size_t i = 0;i < pairs.size();i++)
	{
		small.push_back(pairs[i].first);
		big.push_back(pairs[i].second);
	}

	std::vector<int> mainChain = fordJohnson(big);

	for(size_t i = 0;i < small.size();i++)
	{
		std::vector<int>::iterator pos;

		pos = std::lower_bound(mainChain.begin(), mainChain.end(), small[i]);
		mainChain.insert(pos, small[i]);
	}
	if(hasleftover)
	{
		std::vector<int>::iterator pos;
		pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
		mainChain.insert(pos,leftover);
	}
	return(mainChain);

}
