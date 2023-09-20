
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & other ) : _map(other._map) {}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange&	BitcoinExchange::operator=( BitcoinExchange const & other )
{
	if (this != &other)
		this->_map = other._map;
	return (*this);
}

void				BitcoinExchange::fillDatabase( std::string const & )
{

}

void				BitcoinExchange::exchanger( void ) const
{

}