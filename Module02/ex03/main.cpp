
#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

int	main()
{
	Point	const a(1, 1);
	Point	const b(1, 1);
	Point	const c(7, 18);

	Point	const p(1.5f , 1.5f);

	if (!bsp(a, b, c, p))
		std::cout << "ENDL" << std::endl;
}