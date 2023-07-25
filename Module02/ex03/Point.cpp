
#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

Point::Point() : _x(0), _y(0)
{
	
}

Point::Point( float const f1, float const f2 ) : _x(f1), _y(f2)
{

}

Point::Point( const Point &point) : _x(point._x), _y(point._y)
{

}

Point	&Point::operator=( const Point &point )
{

	if (this != &point)
	{
	}
	return (*this);
}

Point::~Point( void )
{

}

Fixed const		Point::getX( void ) const
{
	return (this->_x);
}

Fixed const		Point::getY( void ) const
{
	return (this->_y);
}

bool	Point::operator==( const Point &point ) const
{
	if (this->getX() == point.getX() && this->getY() == this->getY())
		return (true);
	return(false);
}

void	Point::printPoint( void ) const 
{
	std::cout << "(" << this->_x << ", " << this->_y << ")" << std::endl;
}
