
#pragma once

#include <map>
#include <string>

class	BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & );
		~BitcoinExchange();
		BitcoinExchange&	operator=( BitcoinExchange const & );

		void	fillDatabase( void );
		void	printDatabase( char ) const;
	private:
		std::map<std::string, double>	_map;
};
