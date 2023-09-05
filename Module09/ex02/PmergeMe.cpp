
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe( PmergeMe const & other )
{
	*this = other;
}

PmergeMe::~PmergeMe(){}

PmergeMe&	PmergeMe::operator=( PmergeMe const & other )
{
	if (this != &other)
	{

	}
	return (*this);
}

