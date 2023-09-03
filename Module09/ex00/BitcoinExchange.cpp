
#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <ctime>

//*********************************************************************************//
//                               BitcoinExchange class                             //
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
//                       BitcoinExchange::InputFileException                       //
//*********************************************************************************//

BitcoinExchange::InputFileException::InputFileException(){}

BitcoinExchange::InputFileException::InputFileException(std::string const & msg) : _msg(msg) {}

BitcoinExchange::InputFileException::~InputFileException() throw() {}

char const *	BitcoinExchange::InputFileException::what() const throw()
{
	return (this->_msg.c_str());
}

//*********************************************************************************//
//                        BitcoinExchange member functions                         //
//*********************************************************************************//

void	BitcoinExchange::fillData( std::string const & dataFile )
{
	std::ifstream	file( dataFile.c_str() );
	std::string		line;
	float			exchangeRate;
	int				year, month, day;

	if (file.fail())
		throw (BitcoinExchange::InputFileException("Database file not found"));
	this->_database.clear();
	while (!file.eof())
	{
		std::getline(file, line);
	}
	file.close();
	// parse into map <date, float>
}

void	BitcoinExchange::showResults( std::string const & inputFile ) const
{
	std::tm			*time;
	time_t			raw;
	std::ifstream	input(inputFile.c_str());
	std::string		line;
	

	if (input.fail())
		throw(BitcoinExchange::InputFileException("Input file error"));
	while (!input.eof())
	{
		getline(input, line);

	}






	std::time (&raw);
	time = std::localtime(&raw);
	//std::cout << std::mktime(time) << std::endl;
	std::cout << "Real time" << std::endl;
	std::cout << "Year: " << time->tm_year + 1900 << ", Month: " << time->tm_mon + 1 << ", Day: "
	          << time->tm_mday << std::endl;
	// for each element of inputFile :
	// 1) check date format
	// 2) check number errors
	// 3) search date into BitcoinExchange::_database
	// 4) multiply number of bitcoins by the exchange rate in that date
	// 5) display line in the following format : "DATE, MULTIPLIED_VALUE"
}

//*********************************************************************************//
//                        BitcoinExchange static functions                         //
//*********************************************************************************//

bool	BitcoinExchange::invalidDate(int year, int month, int day)
{
	std::tm		*timeStruct;
	time_t		time;

	if (year <= 0 || month <= 0 || day <= 0)
		return (true);
	if (day > 31 || month > 12)
		return (true);

	//std::cout << "Year: " << year << ", Month: " << month << ", Day: " << day << std::endl;
	std::time(&time);
	timeStruct = localtime(&time);
	timeStruct->tm_year = year - 1900;
	timeStruct->tm_mon = month - 1;
	timeStruct->tm_mday = day;

	time = std::mktime(timeStruct);

	if (time > std::time(NULL))
		return (true);
	return (false);
}