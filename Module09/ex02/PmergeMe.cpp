
#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

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

void	PmergeMe::mergeInsertionSort()
{

}

void	PmergeMe::mergeResult(void)
{
	clock_t	start = clock() * 1000000;
	std::cout << "clocks: " << start << std::endl;

	/*		CODE		*/

	clock_t end = clock() * 1000000;
	std::cout << "clocks: " << start << std::endl;

	double elapsedTime = static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC);

	std::cout << "Elapsed time: " << elapsedTime << std::endl;
}

void	PmergeMe::displayContainers(void) const
{
	size_t const	vLength = _vec.size();
	size_t const	dLength = _deq.size();

	std::cout << "Vector Container: " << std::endl;
	for (size_t i = 0; i < vLength; i++)
	{
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Deque Container: " << std::endl;
	for (size_t i = 0; i < dLength; i++)
	{
		std::cout << _deq[i] << " ";
	}
	std::cout << std::endl;
}