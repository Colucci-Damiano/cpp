
#include "Fixed.hpp"
#include <iostream>

// Default constructor

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

// Destruuctor

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy constructor

Fixed::Fixed( const Fixed &fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &fixed)
		*this = fixed;
}

// Copy assignment operator

Fixed & Fixed::operator = ( const Fixed &fixed )
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &fixed)
	{
		this->_fixedValue = fixed.getRawBits();
	}
	return (*this);
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

const int	Fixed::_fractBits = 8;