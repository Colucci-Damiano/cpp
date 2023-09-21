
#include "BitcoinExchange.hpp"

#include <fstream>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & other ) : _map(other._map) {}

BitcoinExchange::BitcoinExchange( std::string const & inputFile )
{
	(void)inputFile;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange&	BitcoinExchange::operator=( BitcoinExchange const & other )
{
	if (this != &other)
		this->_map = other._map;
	return (*this);
}

void				BitcoinExchange::fillMap( std::string const & inputFile )
{
	(void)inputFile;
}

void				BitcoinExchange::exchanger( void ) const
{

}