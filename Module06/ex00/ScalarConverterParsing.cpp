
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>

bool	ScalarConverter::isChar( std::string const & type )
{
	if (type.length() == 1 && !isdigit(type[0]))
		return (true);
	if (type.length() == 3 && type[0] == '\'' && type[2] == '\'')
		return (true);
	return (false);
}

bool	ScalarConverter::checkNotDiplayableChar( int i )
{
	return (i < 32 || i > 127);
}

bool	ScalarConverter::checkIntOverflow( std::string const & type )
{
	size_t			index = 0;
	size_t const	size = type.length();
	long int		n = 0;

	if (type[index] == '-' || type[index] == '+')
		index++;
	while (index < size && isdigit(type[index]))
	{
		n = n * 10 + (type[index] - 48);
		if (n > std::numeric_limits<int>::max() || -n < std::numeric_limits<int>::min())
			return (true);
		index++;
	}
	return (false);
}

bool	ScalarConverter::isInteger( std::string const & type )
{
	size_t		size = type.length();
	size_t		index = 0;
	
	if (type[index] == '+' || type[index] == '-')
		index++;
	while (index < size)
	{
		if (!isdigit(type[index]))
			return (false);
		index++;
	}
	return (true);
}

bool	ScalarConverter::isFloatDouble( std::string const & type )
{
	size_t const	size = type.length();
	size_t			index = 0;
	unsigned int	points = 0;

	if (!type.compare("nan") || !type.compare("+inf") || !type.compare("-inf") || !type.compare("inf") \
	|| !type.compare("nanf") || !type.compare("+inff") || !type.compare("-inff") || !type.compare("inff"))
		return (true);
	while ( (index = type.find('.', index)) != std::string::npos )
	{
		points++;
		if (index == 0 || index == type.length() - 1 || points > 1)
			return (false);
		index++;
	}
	if (points == 0)
		return (false);
	index = 0;
	if (type[index] == '+' || type[index] == '-')
		index++;
	while (index < size - 1)
	{
		if (!isdigit(type[index]) && type[index] != '.')
			return (false);
		index++;
	}
	if (!isdigit(type[index]) && type[index] != 'f')
		return (false);
	return (true);
}

ScalarConverter::types	ScalarConverter::detectType( std::string const & type )
{
	types	var = UNKNOWN;

	if (type.empty())
		var = UNKNOWN;
	else if (isChar( type ))
		var = CHAR;
	else if (isInteger( type ))
		var = INT;
	else if (isFloatDouble( type ))
	{
		if (!type.compare("nan") || !type.compare("+inf") || !type.compare("-inf") || !type.compare("inf"))
			var = DOUBLE;
		else if (!type.compare("nanf") || !type.compare("+inff") || !type.compare("-inff") || !type.compare("inff"))
			var = FLOAT;
		else
			type[type.length() - 1] == 'f' ? var = FLOAT : var = DOUBLE;
	}
	return (var);
}
