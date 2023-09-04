
#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>

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
	//float			exchangeRate;
	//int				year, month, day;

	if (file.fail())
		throw (BitcoinExchange::InputFileException(dataFile + " file not found!"));
	this->_database.clear();
	// parse into map <date, float>
	while (!file.eof())
	{

	}
	file.close();
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


// Parse string date in format YYYY-MM-DD
// Return date in time_t value, -1 in case of errors or wrong format
// time_t seconds correspond to the begining of the day

time_t	BitcoinExchange::parseDate( std::string const & s )
{
	size_t	length = s.length();
	std::tm	timeStruct = {};
	time_t	date;

	std::cout << timeStruct.tm_gmtoff << std::endl;
	std::cout << timeStruct.tm_hour << std::endl;
	std::cout << timeStruct.tm_isdst << std::endl;
	std::cout << timeStruct.tm_mday << std::endl;
	std::cout << timeStruct.tm_min << std::endl;
	std::cout << timeStruct.tm_mon << std::endl;
	std::cout << timeStruct.tm_sec << std::endl;
	std::cout << timeStruct.tm_wday << std::endl;
	std::cout << timeStruct.tm_yday << std::endl;
	std::cout << timeStruct.tm_year << std::endl;
	std::cout << timeStruct.tm_zone << std::endl;
	if (length != 10 || s[4] != '-' || s[7] != '-')
		return (-1);
	for( size_t i = 0; i < length; i++)
	{
		if (i != 4 && i != 7)
			if (!std::isdigit(s[i]))
				return (-1);
	}
	timeStruct.tm_year = std::atoi(s.substr(0, 4).c_str()) - 1900;
	timeStruct.tm_mon = std::atoi(s.substr(5, 2).c_str()) - 1;
	timeStruct.tm_mday = std::atoi(s.substr(7, 2).c_str());
	date = std::mktime(&timeStruct);
	return (date);
}

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