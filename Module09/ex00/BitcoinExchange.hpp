
#pragma once

#include <map>
#include <string>

class	BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & );
		virtual ~BitcoinExchange();
		BitcoinExchange&	operator=( BitcoinExchange const & );

		void	fillDatabase( void );
		void	printDatabase( char ) const;
		void	exchanger( std::string const & ) const;
		void	printLine(std::string const & date, std::string const & value) const;
	private:
		std::map<std::string, double>	_map;
};
