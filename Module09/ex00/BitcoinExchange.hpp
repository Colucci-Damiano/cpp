
#pragma once

#include <string>
#include <map>

class	BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & );
		BitcoinExchange( std::string const & );
		~BitcoinExchange();
		BitcoinExchange&	operator=( BitcoinExchange const & );

		void				fillMap( std::string const &  );
		void				exchanger( void ) const;
	private:
		std::map<std::string, double>	_map;
};