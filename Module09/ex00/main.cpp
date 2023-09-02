
#include "BitcoinExchange.hpp"
#include <iostream>

int	main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cout << "Error, invalid arguments.\nUsage : ./btc <input_file>" << std::endl;
		return (1);
	}

	BitcoinExchange		data(av[1]);


	return (0);
}