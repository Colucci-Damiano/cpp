
#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & other );
		BitcoinExchange( std::string const & file );
		~BitcoinExchange();
		BitcoinExchange&	operator=( BitcoinExchange const & other );

		class InputFileException : public std::exception
		{
			public:
				InputFileException();
				InputFileException( std::string const & );
				virtual ~InputFileException() throw();

				char const*	what( void ) const throw();
			private:
				std::string	_msg;
		};

		void	fillData(std::string const & dataFile);
		void	showResults(std::string const & inputFile) const ;
	private:
		std::map<time_t, float>		_database;
};