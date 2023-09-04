
#include "BitcoinExchange.hpp"
#include <iostream>
#include <ctime>

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
		std::string			line;
		time_t				date;

		//data.showResults(av[1]);
		//int	year, month, day;
		(void)av;
		while (!std::cin.fail())
		{
			std::cout << "Insert date in format YYYY-MM-DD: ";
			std::cin >> line;
			date = BitcoinExchange::parseDate(line);
			std::cout << date << std::endl;
			std::cout << std::localtime(&date)->tm_year + 1900 << std::endl;
			std::cout << std::localtime(&date)->tm_mon + 1 << std::endl;
			std::cout << std::localtime(&date)->tm_mday << std::endl;
		}
	}
	catch(BitcoinExchange::InputFileException & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	return (0);
}