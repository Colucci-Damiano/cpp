
#include "BitcoinExchange.hpp"

#include <fstream>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & other ){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange&	BitcoinExchange::operator=( BitcoinExchange const & other )
{
	if (this != &other){

	}
	return (*this);
}

void	BitcoinExchange::fillDatabase( void )
{
	std::ifstream		file("data.csv");

	std::string			buffer;
	std::string			value;
	do
	{
		std::getline(file, buffer, ',');
		std::getline(file, value);
		//_map.insert(); /Insert value in map ??
	}
	while (!file.eof());
}
