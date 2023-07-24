
#include "Fixed.hpp"
#include <iostream>
#include <bitset>

int	main()
{
	Fixed	a( 4.6f );
	Fixed	b( 3.5f );
	Fixed	c = a + b;
	Fixed	d = a / b;
	Fixed	e = a * b;

	std::cout << "a is : " << a << std::endl;
	std::cout << "b is : " << b << std::endl;
	std::cout << "c is a + b : " << c << std::endl;
	std::cout << "d is a / b : " << d << std::endl;
	std::cout << "e is a * b : " << e << std::endl;
} 