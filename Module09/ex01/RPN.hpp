
#pragma once

#include <stack>
#include <string>

class RPN
{
	private:
		RPN();
		RPN( RPN const & other );
		~RPN();
		RPN&	operator=( RPN const & other );

		static int	operations( int a1, int a2, char token );
	public:
		static void	reversePolishNotation( std::string const & s );
};