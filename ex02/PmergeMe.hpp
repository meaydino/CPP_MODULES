#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include<vector>
#include<deque>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		std::vector<std::pair<int , int> > _pairs;
		std::vector<int> _mainChain;//büyük elemanlar
		std::vector<int> _pend;//küçük elemanlar
		std::vector<int> fordJohnson(std::vector<int> numbers);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		bool parseInput(int ac, char **av);
		void sort();
		void makePairs();
		void splitPairs();

};

#endif
