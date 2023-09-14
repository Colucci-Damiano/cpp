
#pragma once

#include <string>
#include <vector>
#include <deque>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe( PmergeMe const & other );
		~PmergeMe();
		PmergeMe&	operator=( PmergeMe const & other );

		void	addNumber(int const);
		void	displayContainers(void) const;
		void	mergeInsertionSort(void);

	private:
		static unsigned int		_K;
		std::vector<int>		_vec;
		std::deque<int>			_deq;
};