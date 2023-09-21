
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

		void				fillMap( std::string const & );
		void				exchanger( std::string const & ) const;
	private:
		std::map<std::string, double>	_map;
		void				printLine(std::string const &, double const &) const;
};