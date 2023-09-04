
#include "RPN.hpp"
#include "iostream"

int	main( int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			RPN::reversePolishNotation(av[1]);
		}
		catch( std::exception & e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	return (0);
}