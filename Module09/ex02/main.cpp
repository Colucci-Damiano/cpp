
#include "PmergeMe.hpp"

#include <iostream>

int	main(int ac, char **av)
{
	PmergeMe	merge;

	try
	{
		for (int i = 1; i < ac; i++)
		{
			merge.loadArg(av[i]);
		}
		merge.vectorAlgorithm();
		merge.dequeAlgorithm();
		merge.printArgs();
	}
	catch(std::runtime_error & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}