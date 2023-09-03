
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

		//data.showResults(av[1]);
		int	year, month, day;
		(void)av;
		while (!std::cin.eof())
		{
			std::cout << "Enter year>>";
			std::cin >> year;
			std::cout << "Enter month>>";
			std::cin >> month;
			std::cout << "Enter day>>";
			std::cin >> day;
			if (BitcoinExchange::invalidDate(year, month, day))
				std::cout << "Invalid date!" << std::endl;
			else
				std::cout << "Valid date!" << std::endl;
		}
	}
	catch(BitcoinExchange::InputFileException & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	return (0);
}