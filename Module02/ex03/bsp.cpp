
#include "Point.hpp"
#include "Fixed.hpp"

bool	pointInPerimeter(const Point a, const Point b, const Point c, const Point p)
{
	if (a == p || b == p || c == p)
		return (true);
	if (((p.getX() - b.getX()) / (a.getX() - b.getX())) == ((p.getY() - b.getY()) / (a.getY() - b.getY())))
		return (true);
	if (((p.getX() - b.getX()) / (c.getX() - b.getX())) == ((p.getY() - b.getY()) / (c.getY() - b.getY())))
		return (true);
	if (((p.getX() - c.getX()) / (a.getX() - c.getX())) == ((p.getY() - c.getY()) / (a.getY() - c.getY())))
		return (true);
	return (false);
}

bool	bsp(const Point a, const Point b, const Point c, const Point p)
{
	if (a == b || b == c || a == c)
	{
		std::cout << "Warning : Two or more points of the triangles coincide" << std::endl;
		return (false);
	}
	if (pointInPerimeter(a, b, c, p))
	{
		std::cout << "Warning : The point is a vertex or is in the edges" << std::endl;
		return (false);
	}
	Fixed x1 = a.getX();
	Fixed y1 = a.getY();
	Fixed x2 = b.getX();
	Fixed y2 = b.getY();
	Fixed x3 = c.getX();
	Fixed y3 = c.getY();
	Fixed x = p.getX();
	Fixed y = p.getY();

	Fixed d1 = (x - x1) * (y2 - y1) - (x2 - x1) * (y - y1);
	Fixed d2 = (x - x2) * (y3 - y2) - (x3 - x2) * (y - y2);
	Fixed d3 = (x - x3) * (y1 - y3) - (x1 - x3) * (y - y3);

	if (d1 >= 0 && d2 >= 0 && d3 >= 0)
		return true;
	else if (d1 <= 0 && d2 <= 0 && d3 <= 0)
		return true;
	else
		return false;
	return (true);
}