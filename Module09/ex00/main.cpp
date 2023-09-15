
#include "BitcoinExchange.hpp"
#include <iostream>
#include <limits>
#include <ctime>

bool	isNumber( std::string const & str )
{
	size_t const	len = str.length();
	size_t			i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	if (len == 0)
		return(false);
	for (; i < len; i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

int		atoiLimits( std::string const & str )
{
	long int		n = 0;
	long int const	maxInt = std::numeric_limits<int>::max();
	size_t			len = str.length();
	size_t			i = 0;
	int				sign = 1;

	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1 ;
		i++;
	}
	for(; i < len; i++)
	{
		if (std::isdigit(str[i]))
		{
			n = n * 10 + (str[i] - 48);
			if (n > maxInt)
				throw(std::runtime_error("Overflow"));
		}
		else
			break ;
	}
	return (n * sign);
}

int		toNumber( std::string const & str )
{
	if (!isNumber(str))
		throw(std::runtime_error("Bad input"));
	return(::atoiLimits(str));
}

int	main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cerr << "Error, invalid arguments.\nUsage : ./btc <input_file>" << std::endl;
		return (1);
	}
	return (0);
}