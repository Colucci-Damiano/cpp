
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
		std::cout << "Error\nTwo or more points of the triangles coincide" << std::endl;
		return (false);
	}
	if (pointInPerimeter(a, b, c, p))
	{
		std::cout << "Error\nThe point is a vertex or is in the edges" << std::endl;
		return (false);
	}
	return (true);
}