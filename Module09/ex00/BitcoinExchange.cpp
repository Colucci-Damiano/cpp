
#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <stdlib.h>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & other ) : _map(other._map) {}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange&	BitcoinExchange::operator=( BitcoinExchange const & other )
{
	if (this != &other)
	{
		this->_map = other._map;
	}
	return (*this);
}

void	BitcoinExchange::fillDatabase( void )
{
	std::ifstream		file("data.csv");
	std::string			buffer;
	std::string			sValue;
	double				dValue;

	std::getline(file, buffer);
	do
	{
		std::getline(file, buffer, ',');
		std::getline(file, sValue);
		{
			std::stringstream	ss(sValue);
			ss >> dValue;
		}
		_map.insert(std::pair<std::string, double>(buffer, dValue)); //Insert value in map ??
	}
	while (!file.eof());
}

void	BitcoinExchange::printDatabase( char c ) const
{
	std::map<std::string, double>::const_iterator	it = _map.begin();
	std::map<std::string, double>::const_iterator	end = _map.end();

	for (; it != end; it++)
	{
		std::cout << it->first << c << it->second << std::endl;
	}
}