
#include "BitcoinExchange.hpp"
#include <iostream>


int	main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cerr << "Error\nUsage: ./btc <inputFile>" << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange		btc("data.csv");
		btc.exchanger(av[1]);
	}
	catch( std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}