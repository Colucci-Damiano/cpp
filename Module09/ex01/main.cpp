
#include "RPN.hpp"
#include "iostream"


int	main( int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error\nUsage: ./RPN <numbers in one argument>" << std::endl;
		std::cout << "Example: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
		return (1);
	}
	try
	{
		RPN::reversePolishNotation(av[1]);
	}
	catch( std::exception & e )
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}