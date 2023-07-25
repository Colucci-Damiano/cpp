
#include "Point.hpp"
#include "Fixed.hpp"

//(x - x1)/(x2 - x1) = (y - y1)/(y2 - y1)

bool	checkInPerimeter(const Point a, const Point b, const Point c, const Point p)
{
	if (a.getX() == p.getX() && a.getY() == p.getY())
		return (true);
	if (b.getX() == p.getX() && b.getY() == p.getY())
		return (true);
	if (c.getX() == p.getX() && c.getY() == p.getY())
		return (true);
	if (((p.getX() - b.getX()) / (a.getX() - b.getX())) == \
	((p.getY() - b.getY()) / (a.getY() - b.getY())))
		return (true);
	if (((p.getX() - b.getX()) / (c.getX() - b.getX())) == \
	((p.getY() - b.getY()) / (c.getY() - b.getY())))
		return (true);
	if (((p.getX() - c.getX()) / (a.getX() - c.getX())) == \
	((p.getY() - c.getY()) / (a.getY() - c.getY())))
		return (true);
	return (false);
}

bool	bsp(const Point a, const Point b, const Point c, const Point p)
{
	if (checkInPerimeter(a, b, c, p))
	{
		std::cout << "The point is a vertex or is in the edges" << std::endl;
		return (false);
	}
	return (true);
}