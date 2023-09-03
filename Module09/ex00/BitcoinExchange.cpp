
#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>

//*********************************************************************************//
//                         BitcoinExchange class                                   //
//*********************************************************************************//

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & other)
{
	if (this != &other)
		*this = other;
}

BitcoinExchange::BitcoinExchange( std::string const & fileData )
{
	fillData( fileData );
}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const & other)
{
	if (this != &other)
	{
		this->_database = other._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

//*********************************************************************************//
//                            BitcoinExchange exception                            //
//*********************************************************************************//

BitcoinExchange::InputFileException::InputFileException(){}

BitcoinExchange::InputFileException::InputFileException(std::string const & msg) : _msg(msg) {}

BitcoinExchange::InputFileException::~InputFileException() throw() {}

char const *	BitcoinExchange::InputFileException::what() const throw()
{
	return (this->_msg.c_str());
}

//*********************************************************************************//
//                         BitcoinExchange member functions                        //
//*********************************************************************************//

void	BitcoinExchange::fillData( std::string const & dataFile )
{
	std::ifstream	file( dataFile.c_str() );
	std::string		buffer;

	if (file.fail())
		throw (BitcoinExchange::InputFileException("Input file error"));
	std::getline(file, buffer, (char)EOF);
	std::cout << buffer << std::endl;
	file.close();
	// parse into map <date, float>
}

void	BitcoinExchange::showResults( std::string const & inputFile ) const
{
	(void)inputFile;
	// for each element of inputFile :
	// 1) check date format
	// 2) check number errors
	// 3) search date into BitcoinExchange::_database
	// 4) multiply number of bitcoins by the exchange rate in that date
	// 5) display line in the following format : "DATE, MULTIPLIED_VALUE"
}