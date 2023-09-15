
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
		template<typename IT>
		void	insertionSort(IT, IT);
		template<typename T, typename IT>
		void	mergeInsertionSort(T &, IT, IT);
		void	mergeResult(void);

	private:
		static unsigned int const		_K;
		std::vector<int>				_vec;
		std::deque<int>					_deq;
};