
#include "BitcoinExchange.hpp"
#include <iostream>

int	main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cout << "Error, invalid arguments.\nUsage : ./btc <input_file>" << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange		data("data.csv");

		data.showResults(av[1]);
	}
	catch(BitcoinExchange::InputFileException & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	return (0);
}