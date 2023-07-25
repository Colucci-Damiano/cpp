
#include "Fixed.hpp"
#include <iostream>
#include <bitset>

int	main()
{
	Fixed	a( 4.6f );
	Fixed	b( 3.5f );
	Fixed	x( 5 );
	Fixed	y( - 9 );
	Fixed	c = a + b;
	Fixed	d = a / b;
	Fixed	e = a * b;
	Fixed	z(0.0f);

	std::cout << "a is : " << a << std::endl;
	std::cout << "b is : " << b << std::endl;
	std::cout << "c is a + b : " << c << std::endl;
	std::cout << "d is a / b : " << d << std::endl;
	std::cout << "e is a * b : " << e << std::endl;
	std::cout << "d * b : " << (d * b) << std::endl;
	std::cout << "y is :" << y << std::endl;
	std::cout << "5 - (-9) is : " << (x - y) << std::endl;
} 
