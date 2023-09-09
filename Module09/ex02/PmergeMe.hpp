
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

		std::vector<int>&	getVector(void);
		std::deque<int>&	getDeque(void);

		void	loadArg( std::string const & );
		void	vectorAlgorithm( int start, int end );
		void	vectorMerge(int start, int q, int end);
		void	vectorInsertion(int start, int end);
		void	dequeAlgorithm( void );
		void	printArgs( void ) const;
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		static const int	_K;
};

bool	isNumber( std::string const & );