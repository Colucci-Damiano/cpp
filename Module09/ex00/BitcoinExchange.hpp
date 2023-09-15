
#pragma once

#include <map>

class	BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & );
		~BitcoinExchange();
		BitcoinExchange&	operator=( BitcoinExchange const & );

		void	fillDatabase( void );
	private:
		std::map<std::string, double>	_map;
};
