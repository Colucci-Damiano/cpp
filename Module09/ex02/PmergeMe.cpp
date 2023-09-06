
#include "PmergeMe.hpp"

#include <string>
#include <limits>
#include <exception>
#include <iostream>
#include <cstdlib>

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
		this->_deque = other._deque;
		this->_vector = other._vector;
	}
	return (*this);
}

const int PmergeMe::_K = 5;

void	PmergeMe::loadArg( std::string const & number )
{
	int		n = 0;

	if (!isNumber(number))
		throw (std::runtime_error("invalid argument: [" + number + "]"));

	n = std::atoi(number.c_str());
	this->_vector.push_back(n);
	this->_deque.push_back(	n);
}

void	PmergeMe::vectorInsertion(int start, int end)
{
    for (int i = start; i < end; i++) {
        int tempVal = this->_vector[i + 1];
        int j = i + 1;
        while (j > start && this->_vector[j - 1] > tempVal) {
            this->_vector[j] = this->_vector[j - 1];
            j--;
        }
        this->_vector[j] = tempVal;
    }
}

/* void	PmergeMe::vectorMerge(int start, int q, int end)
{
	int n1 = q - start + 1;
    int n2 = end - q;
    int[] LA = Arrays.copyOfRange(A, p, q +1);
    int[] RA = Arrays.copyOfRange(A, q+1, r +1);
    int RIDX = 0;
    int LIDX = 0;
    for (int i = start; i < end - start + 1; i++) {
        if (RIDX == n2) {
            A[i] = LA[LIDX];
            LIDX++;
        } else if (LIDX == n1) {
            A[i] = RA[RIDX];
            RIDX++;
        } else if (RA[RIDX] > LA[LIDX]) {
            A[i] = LA[LIDX];
            LIDX++;
        } else {
            A[i] = RA[RIDX];
            RIDX++;
        }
    }
} */

void	PmergeMe::vectorAlgorithm(int start, int end)
{
	if (end - start > PmergeMe::_K)
	{
		int		q = ( end - start ) / 2;
		this->vectorAlgorithm(start, q);
		this->vectorAlgorithm(q + 1, end);
		this->vectorMerge(start, q, end);
	}
	else
	{
		this->vectorInsertion(start, end);
	}
}

void	PmergeMe::dequeAlgorithm(void)
{

}

void	PmergeMe::printArgs( void ) const
{
	size_t	n = this->_vector.size();

	for (size_t i = 0; i < n ; i++)
		std::cout << "arg " << i + 1 << " is: " << _vector[i] << std::endl;
}

bool	isNumber(std::string const & number)
{
	long int		n = 0;
	size_t const	size = number.length();

	for (size_t i = 0; i < size; i++)
	{
		if (!isdigit(number[i]))
			return (false);
		n = n * 10 + (static_cast<int>(number[i]) - 48);
		if (n > std::numeric_limits<int>::max())
			return (false);
	}
	return (true);
}