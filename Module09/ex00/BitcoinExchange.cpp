
#include "BitcoinExchange.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & other ) : _map(other._map) {}

BitcoinExchange::BitcoinExchange( std::string const & database )
{
	fillMap(database);
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange&	BitcoinExchange::operator=( BitcoinExchange const & other )
{
	if (this != &other)
		this->_map = other._map;
	return (*this);
}

void				printMap( std::map<std::string, double> const & map )
{
	std::map<std::string, double>::const_iterator		it = map.begin();
	std::map<std::string, double>::const_iterator		end = map.end();

	while (it != end)
	{
		std::cout << it->first << '|' << it->second << std::endl;
		it++;
	}
}

bool				invalidDate(std::string const & date)
{
	std::istringstream	ss(date);
	int					year, month, day;
	char				delim;

	if (ss >> year >> delim >> month >> delim >> day)
	{
		if (year >= 2009 && (month >= 1 && month <= 12) && (day >= 1 && day  <= 31))
			return (false);
	}
	return (true);
}

void				printExchange(std::string const & date, double const & value, double const & exchanger)
{
	if (value < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if (value > 1000.0)
		std::cout << "Error: too large number." << std::endl;
	else
		std::cout << date << " => " << value << " = " << value * exchanger << std::endl;
}

void				BitcoinExchange::printLine(std::string const & date, double const & value) const
{
	if (invalidDate(date))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return ;
	}
	std::map<std::string, double>::const_reverse_iterator		rit = _map.rbegin();
	std::map<std::string, double>::const_reverse_iterator		rend = _map.rend();

	for(; rit != rend; rit++)
	{
		if ((rit->first).compare(date) <= 0)
		{
			printExchange(date, value, rit->second);
			break ;
		}
	}
}

void				BitcoinExchange::fillMap( std::string const & database )
{
	std::string			line, date;
	double				value = 0;
	std::ifstream		is(database.c_str());

	if (is.fail())
		throw(std::runtime_error("Database file not found"));
	this->_map.erase(this->_map.begin(), this->_map.end());
	std::getline(is, line);
	std::cout << "First line: " << line << std::endl;
	while (!is.eof())
	{
		std::getline(is, line);
		std::istringstream	iss(line);

		if (iss.good())
		{
			std::getline(iss, date, ',');
			iss >> value;
			if (!invalidDate(date))
				_map[date] = value;
		}
	}
	//printMap(this->_map);
}

void				BitcoinExchange::exchanger( std::string const & inputFile ) const
{
	std::string		line, date;
	double			value = 0;
	std::ifstream	is(inputFile.c_str());

	if (is.fail())
		throw(std::runtime_error("Input file not found"));

	std::getline(is, line);
	while (!is.eof())
	{
		std::getline(is, line);
		std::istringstream	iss(line);

		if (iss.good())
		{
			std::getline(iss, date, '|');
			iss >> value;
			printLine(date, value);
		}
	}
}