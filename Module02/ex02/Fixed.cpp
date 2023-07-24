
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

void printBits(unsigned int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; --i) {
        unsigned int mask = 1 << i;
        std::cout << ((num & mask) ? 1 : 0);
    }
    std::cout << std::endl;
}

//Initialization of non-member attributes

const int	Fixed::_fractBits = 8;

//Constructors

Fixed::Fixed( void )
{
	this->setRawBits(0);
}

Fixed::~Fixed( void ){}

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

	result = roundf( raw * (float)(1 << this->_fractBits) );
	this->setRawBits( ( int ) result );
}

//Operator overloads

Fixed	&Fixed::operator= ( const Fixed &fixed )
{
	if (this != &fixed)
	{
		this->_fixedValue = fixed.getRawBits();
	}
	return (*this);
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	if (this->getRawBits() < fixed.getRawBits())
		return (false);
	return (true);
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	if (this->getRawBits() < fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	if (this->getRawBits() >= fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	if (this->getRawBits() <= fixed.getRawBits())
		return(true);
	return(false);
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	if (this->getRawBits() == fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	if (this->getRawBits() != fixed.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	int		sum;
	Fixed	obj;

	sum = this->getRawBits() + fixed.getRawBits();
	obj.setRawBits(sum);
	return (obj);
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	int	diff;

	diff = this->getRawBits() - fixed.getRawBits();
	return (Fixed(diff));
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	long int	mult;
	Fixed		obj;

	mult = (long int)this->getRawBits() * (long int)fixed.getRawBits();
	mult >>= this->_fractBits;
	obj.setRawBits(mult);
	return (obj);
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	long int	div;
	Fixed		obj;

	div = ((long int )this->getRawBits() << this->_fractBits) / ((long int)fixed.getRawBits());
	obj.setRawBits(div);
	return (obj);
}

Fixed	&Fixed::operator++( void )
{
	std::cout << "Called ++operaor prefix" << std::endl;
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator++( int )
{
	Fixed	&cpy(*this);
	
	this->setRawBits(getRawBits() + 1);
	std::cout << "Called ++operaor postfix" << std::endl;
	return (cpy);
}

Fixed	&Fixed::operator--( void )
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	&Fixed::operator--( int )
{
	Fixed	&cpy(*this);
	
	this->setRawBits(getRawBits() - 1);
	return (cpy);
}

// Public member functions

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

//Public non-member functions

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f2);
	return (f1);
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return (f2);
	return (f1);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

//Global functions

std::ostream	&operator<<( std::ostream &os, Fixed const &fixed )
{
	if ((fixed.getRawBits() & 0xFF) == 0)
		os << fixed.toInt();
	else
		os << fixed.toFloat();
	return (os);
}
