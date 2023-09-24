
#include "RPN.hpp"

#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <exception>

RPN::RPN(){}

RPN::RPN( RPN const & other )
{
	if (this != &other)
		*this = other;
}

RPN::~RPN(){}

RPN&	RPN::operator=( RPN const & other )
{
	if (this != &other)
	{
	}
	return (*this);
}

int		RPN::operations(int a1, int a2, char token)
{
	if (token == '*')
		return ( a1 * a2 );
	else if (token == '/')
	{
		if (a2 == 0)
			throw(std::runtime_error("Division by 0"));
		return ( a1 / a2 );
	}
	else if (token == '+')
		return ( a1 + a2 );
	else if (token == '-')
		return ( a1 - a2 );
	else
		throw(std::exception());
	return (0);
}

void	RPN::reversePolishNotation( std::string const & s )
{
	int				a1, a2;
	std::stack<int>	container;
	std::string		tokens("/*+-");

	std::string		copy(s);
	size_t const	copyLength = copy.length();

	for( size_t i = 0; i < copyLength; i++ )
	{
		if (std::isdigit(copy[i]))
			container.push(std::atoi(copy.substr(i, 1).c_str()));
		else if (tokens.find(s[i]) != std::string::npos)
		{
			if (container.size() < 2)
				throw (std::runtime_error("Error operator"));
			a2 = container.top();
			container.pop();
			a1 = container.top();
			container.pop();
			container.push(operations(a1, a2, s[i]));
		}
		else if (copy[i] != ' ' && copy[i] != '\t')
			throw(std::runtime_error("Unregognised token"));
	}
	if (container.size() > 1)
		throw(std::runtime_error("Error"));
	while (!container.empty())
	{
		std::cout << container.top() <<  std::endl;
		container.pop();
	}
}