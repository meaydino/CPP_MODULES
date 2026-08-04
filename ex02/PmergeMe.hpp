#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include<vector>
#include<deque>
#include <iostream>


struct Pair
{
	int small;
	int big;
};

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		std::vector<Pair> _pairs;
		std::vector<int> _mainChain;//büyük elemanlar
		std::vector<Pair> _pend;//küçük elemanlar

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		bool parseInput(int ac, char **av);
		void sort();
		void makePairs();
		void splitPairs();
		std::vector<size_t> generateJacobsthalOrder(size_t size);//pend elemlarının ekleme sırasını üretir
		std::vector<int> fordJohnsonVector(std::vector<int> numbers);
		std::deque<int> fordJohnsonDeque(std::deque<int> numbers);


};


#endif
