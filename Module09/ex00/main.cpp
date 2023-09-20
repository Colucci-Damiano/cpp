
#include "BitcoinExchange.hpp"
#include <iostream>


int	main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cerr << "Error\nUsage: ./btc <inputFile>" << std::endl;
		return 1;
	}
	BitcoinExchange		btc(av[1]);

	btc.fillDatabase("data.csv");
	btc.exchanger();
}