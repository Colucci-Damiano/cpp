
#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

void	ScalarConverter::fromChar( std::string const & type )
{
	char	c = 0;
	if (type.length() == 1)
		c = type[0];
	else if (type.length() == 3)
		c = type[1];

	std::cout << "Char: '" << c << "'" << std::endl;
	std::cout << "Int: " << static_cast<int>(c) << std::endl;
	std::cout << "Float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(c) << std::endl;
}

void	ScalarConverter::fromInt( std::string const & type )
{
	int			n = std::atoi(type.c_str());
	bool const	overflow = checkIntOverflow(type);

	if (overflow)
	{
		std::cout << "Int: overflow" << std::endl;
		std::cout << "Char: not printable" << std::endl;
		std::cout << "WARNING: next conversions may be unreliable due to overflow" << std::endl;
	}
	else
	{
		std::cout << "Int: " << n << std::endl; 
		if (checkNotDiplayableChar(n))
			std::cout << "Char: not printable" << std::endl;
		else
			std::cout << "Char: '" << static_cast<char>(n) << "'" << std::endl;
	}
	std::cout << "Float: " << static_cast<float>(n) << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(n) << std::endl;
	
}

void	ScalarConverter::fromFloat( std::string const & type )
{
	char	*endPtr;
	float	f = std::strtof(type.c_str(), &endPtr);
	int		i = static_cast<int>(f);
	bool	impossible = false;

	if (!type.compare("nanf") || !type.compare("+inff") || !type.compare("-inff") || !type.compare("inff"))
		impossible = true;
	
	if (impossible)
		std::cout << "Char: impossible" << std::endl;
	else if (checkNotDiplayableChar(i))
		std::cout << "Char: not printable" << std::endl;
	else
		std::cout << "Char: '" << static_cast<char>(i) << "'" << std::endl;

	if (impossible)
		std::cout << "Int: impossible" << std::endl;	
	else if (checkIntOverflow(type))
		std::cout << "Int: overflow" << std::endl;
	else
		std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << f << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(f) << std::endl;
}

void	ScalarConverter::fromDouble( std::string const & type )
{
	bool	impossible = false;
	char	*endPtr;
	double	d = std::strtod(type.c_str(), &endPtr);
	int		i = static_cast<int>(d);

	if (!type.compare("nan") || !type.compare("+inf") || !type.compare("-inf") || !type.compare("inf"))
		impossible = true;
	if (impossible)	
		std::cout << "Char: impossible" << std::endl;
	else if (checkNotDiplayableChar(i))
		std::cout << "Char: not printable" << std::endl;
	else
		std::cout << "Char: '" << static_cast<char>(i) << "'" << std::endl;
	
	if (impossible)
		std::cout << "Int: impossible" << std::endl;
	else if (checkIntOverflow(type))
		std::cout << "Int: overflow" << std::endl;
	else
		std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << static_cast<double>(d) << "f" << std::endl;
	std::cout << "Double: " << d << std::endl;
}

void	ScalarConverter::convert( std::string const & type )
{
	//Detect type
	types	data = detectType( type );
	//Convert string into that type
	switch (data)
	{
		case CHAR:
			std::cout << "Detected char" << std::endl;
			fromChar(type);
			break;
		
		case INT:
			std::cout << "Detected int" << std::endl;
			fromInt(type);
			break;
		
		case FLOAT:
			std::cout << "Detected float" << std::endl;
			fromFloat(type);
			break;
		
		case DOUBLE:
			std::cout << "Detected double" << std::endl;
			fromDouble(type);
			break;
		
		case UNKNOWN:
			std::cout << "Type of literal " << type << " not detected" << std::endl;
			break;

		default:
			break;
	}
	//Cast the conversion in the other types
	//Display the results
}