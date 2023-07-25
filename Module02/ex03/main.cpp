
#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

int	main()
{
	Point	a(3, 3);
	Point	b(0, 0);
	Point	c(3, 0);

	Point	p(5, 5);
	std::cout << bsp(a, b, c, p) << std::endl;
}