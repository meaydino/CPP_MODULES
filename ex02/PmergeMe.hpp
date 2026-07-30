#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include<vector>
#include<deque>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		bool parseInput(int ac, char **av);
		void sort();

};

#endif
