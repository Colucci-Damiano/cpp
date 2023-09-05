
#pragma once

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe( PmergeMe const & other );
		~PmergeMe();
		PmergeMe&	operator=( PmergeMe const & other );

		void	loadArgs(int ac, char **av);
	private:
};
