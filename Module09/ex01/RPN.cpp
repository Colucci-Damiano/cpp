
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
		return ( a1 / a2 );
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
	std::string		copy(s);
	copy.erase(std::remove(copy.begin(), copy.end(), ' '), copy.end());
	std::cout << copy << std::endl;
	std::stack<int>	container;
	size_t const	length = copy.length();

	for( size_t i = 0; i < length; i++ )
	{
		if (std::isdigit(copy[i]))
			container.push(std::atoi(copy.substr(i, 1).c_str()));
		else if (container.size() >= 2)
		{
			a2 = container.top();
			container.pop();
			a1 = container.top();
			container.pop();
			container.push(operations(a1, a2, s[i]));
		}
		else
			throw (std::exception());
	}
	while (!container.empty())
	{
		std::cout << "Result: " << container.top() <<  std::endl;
		container.pop();
	}
}