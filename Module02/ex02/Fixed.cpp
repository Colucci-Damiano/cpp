
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_fractBits = 8;

Fixed::Fixed( void )
{
	this->setRawBits(0);
}

Fixed::~Fixed( void )
{
}

Fixed::Fixed( const Fixed &fixed )
{
	if (this != &fixed)
		*this = fixed;
}

Fixed::Fixed( const int raw )
{
	int	result;

	result = raw << this->_fractBits;
	this->setRawBits(result);
}

Fixed::Fixed( const float raw )
{
	float	result;

	result = roundf( raw * (1 << this->_fractBits) );
	this->setRawBits( ( int ) result );
}

Fixed & Fixed::operator= ( const Fixed &fixed )
{
	if (this != &fixed)
	{
		this->_fixedValue = fixed.getRawBits();
	}
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	return (this->_fixedValue);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixedValue = raw;
}

float	Fixed::toFloat( void ) const
{
	float	result;
	float	fixed;

	fixed = (float)this->getRawBits();
	result = fixed / (float)(1 << this->_fractBits);
	return (result);
}

int		Fixed::toInt( void ) const
{
	int	result;

	result = this->getRawBits() >> this->_fractBits;
	return ( result );
}

std::ostream	&operator<<( std::ostream &os, Fixed const &fixed )
{
	os << fixed.toFloat();
	return (os);
}
