
#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <iomanip>

unsigned int const	PmergeMe::_K = 3;

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe( PmergeMe const & other ) : _vec(other._vec), _deq(other._deq) {}

PmergeMe::~PmergeMe(){}

PmergeMe&	PmergeMe::operator=( PmergeMe const & other )
{
	if (this != &other)
	{
		this->_vec = other._vec;
		this->_deq = other._deq;
	}
	return (*this);
}

void	PmergeMe::addNumber( int number )
{
	this->_vec.push_back(number);
	this->_deq.push_back(number);
}

template<typename IT>
void	PmergeMe::insertionSort(IT first, IT last)
{
	if (first == last)
		return;
	IT		i = first + 1;
	while ( i != last)
	{
		IT j	= i - 1;
		while ( j != first && *j > *(j - 1) )
		{
			IT	tmp = j - 1;
			std::swap(j, tmp);
			j--;
		}
		i++;
	}
	//std::sort(first, last);
}

template<typename T, typename IT>
void	PmergeMe::mergeInsertionSort(T & container, IT first, IT last)
{
	if (std::distance(first, last) > PmergeMe::_K)
	{
		IT newLast = first + std::distance(first, last) / 2;
		mergeInsertionSort(container, first, newLast);
		mergeInsertionSort(container, newLast, last);

		T	copy(std::distance(first, last));

		std::merge(first, newLast, newLast, last, copy.begin());

		IT	beg = copy.begin();
		IT	end = copy.end();
		std::copy(beg, end, first);
	}
	else
	{
		insertionSort(first, last);
	}
}

void	PmergeMe::displayContainers(void) const
{
	size_t const	vLength = _vec.size();

	for (size_t i = 0; i < vLength; i++)
	{
		std::cout << _vec[i] << " ";
	}

	std::cout << std::endl;
}

void	PmergeMe::mergeResult(void)
{
	std::cout << "\033[31mBefore:	";
	displayContainers();

	clock_t	start = std::clock();
	mergeInsertionSort(_vec, _vec.begin(), _vec.end());
	clock_t end = std::clock();

	clock_t startDeq = std::clock();
	mergeInsertionSort(_deq, _deq.begin(), _deq.end());
	clock_t	endDeq = std::clock();

	std::cout << "\033[32mAfter:	";
	displayContainers();
	std::cout << "\033[0m";

	double elapsedTime = static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC) * 1000000.0;
	std::cout << "Time to process a range of "<< _vec.size() <<" elements with std::vector : " << elapsedTime << " us" << std::endl;

	elapsedTime = static_cast<double>(endDeq - startDeq) / static_cast<double>(CLOCKS_PER_SEC) * 1000000.0;
	std::cout << "Time to process a range of "<< _deq.size() <<" elements with std::deque : " << elapsedTime << " us" << std::endl;
}
