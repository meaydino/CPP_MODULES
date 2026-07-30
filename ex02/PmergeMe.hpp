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

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		bool parseInput(int ac, char **av);
		void sort();
		void makePairs();

};

#endif
