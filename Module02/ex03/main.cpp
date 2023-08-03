
#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

int	main()
{
	Point	const a(3, 1);
	Point	const b(-1, 6);
	Point	const c(-3, 2);

	Point	const p(0.0f , 1.5f);

	if (!bsp(a, b, c, p))
		std::cout << "The point is outside the triangle" << std::endl;
	else
		std::cout << "The point is inside the triangle" << std::endl;
}