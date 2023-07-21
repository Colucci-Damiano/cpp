
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &fixed)
		*this = fixed;
}

Fixed::Fixed( int const raw )
{
	this->_fixedValue = raw << Fixed::_fractBits;
}

// 2.7  3.0 diff = 0.3 if (rounded > raw) fixed = rounded - 1

Fixed::Fixed( float const raw )
{
	float	rounded;
	float	diff;
	
	rounded = std::roundf(raw);
	diff = abs(raw - rounded);
	if (rounded > raw)
		rounded -= 1.0;
}

Fixed & Fixed::operator= ( const Fixed &fixed )
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &fixed)
	{
		this->_fixedValue = fixed.getRawBits();
	}
	return (*this);
}

Fixed & Fixed::operator<< ( std::ostream &cout )
{
	int		fixed;
	int		fract_bits;

	fixed = this->getRawBits() << Fixed::_fractBits;
	fract_bits = 0;
	cout << fixed << "." << fract_bits << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedValue);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixedValue = raw;
}

float	Fixed::toFloat( void ) const
{
	float	value;
	float	fract;
	int		toConv = this->_fixedValue;

	value = (float)(toConv >> Fixed::_fractBits);
	toConv <<= (sizeof(int) - Fixed::_fractBits);
	toConv >>= (sizeof(int)) - Fixed::_fractBits);
	fract = (float)toConv;
	for (int i = 0; i < Fixed::_fractBits; i++)
		fract /= 10.0;
	value += fract;
	return (value);
}

int		Fixed::toInt( void ) const
{

}

const int	Fixed::_fractBits = 8;