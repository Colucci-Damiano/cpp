
#include "ScalarConverter.hpp"
#include <iostream>

int	main( int ac, char **av)
{
	if (ac == 2)
	{
		std::cout << "Conversion of literal: " << av[1] << std::endl;
		ScalarConverter::convert(av[1]);
	}
	else
	{
		std::cout << "Error: invalid arguments\nUsage: ./convert <literal>" << std::endl;
	}
}