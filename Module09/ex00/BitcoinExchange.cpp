
#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <limits>
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
			if (!ss.fail())
				_map.insert(std::pair<std::string, double>(buffer, dValue)); //Insert value in map ??
		}
	}
	while (!file.eof());
	file.close();
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

bool	validDate(std::string const & date)
{
	std::stringstream	ss(date);

	int		year, month, day;
	char	delimiter;

	if (ss >> year >> delimiter >> month >> delimiter >> day)
	{
		if ((year < 0 || year > 2023) || (month > 12 || month < 0) || (day > 31 || day < 0))
			return (false);
		return (true);
	}
	return (true);
}

bool	validValue(std::string const & value)
{
	std::stringstream	ss(value);
	double	dValue;

	if (ss >> dValue)
	{
		if (dValue < 0 )
		{
			std::cerr << "Error: not a positive number." << std::endl;
			return (false);
		} 
		else if (dValue > static_cast<double>(std::numeric_limits<int>::max()))
		{
			std::cerr << "Error: too large a number." << std::endl;
			return (false);
		}
		return (true);
	}
	return (false);
}

void	BitcoinExchange::printLine(std::string const & date, std::string const & value) const
{
	if (!validDate(date))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return ;
	}
	if (!validValue(value))
		return ;
	//Search in the map
	double				dValue;
	std::stringstream	ss(value);
	ss >> dValue;
	std::map<std::string, double>::const_iterator	it = _map.begin();
	std::map<std::string, double>::const_iterator	end = _map.end();

	for (; it != end; it++)
	{
		if (1)
		{
			std::cout << date << " => " << (dValue * it->second) << std::endl;
		}
	}
}

void	BitcoinExchange::exchanger( std::string const & inputFile ) const
{
	std::ifstream		is(inputFile.c_str());

	if (!is.good())
	{
		std::cerr << "Could not oper file: " << inputFile << std::endl;
		return;
	}

	if (_map.empty())
	{
		std::cerr << "Error\nEmpty database; create file data.csv in current directory" << std::endl;
		return ;
	}

	std::string				line;
	std::string				value;
	std::string				date;

	std::getline(is, line);
	while (!is.eof())
	{
		std::getline(is, line);
		{
			std::stringstream	ss(line);
			std::getline(ss, date, '|');
			std::getline(ss, value);
			printLine(date, value);
		}
	}
	is.close();
}