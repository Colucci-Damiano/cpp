
#include "BitcoinExchange.hpp"
#include <iostream>
#include <limits>
#include <ctime>

int	main( int ac, char **av )
{
	(void)av;
	if (ac != 2)
	{
		std::cerr << "Error, invalid arguments.\nUsage : ./btc <input_file>" << std::endl;
		return (1);
	}
	BitcoinExchange		btc;

	btc.fillDatabase();
	btc.exchanger(av[1]);
	return (0);
}