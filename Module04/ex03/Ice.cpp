
#include "Ice.hpp"
#include <iostream>

// Default constructor

Ice::Ice() : AMateria()
{
	this->_type = "ice";
	std::cout << "Default constructor calle by Ice" << std::endl;
}

// Copy constructor

Ice::Ice( const Ice &ice )
{
	std::cout << "Copy constructor called by Ice" << std::endl;
	if (this != &ice)
		*this = ice;
}

// Copy assignment operator

Ice	&Ice::operator=( const Ice &ice )
{
	if (this != &ice)
	{
	}
	return (*this);
}

// Destructor

Ice::~Ice()
{
	std::cout << "Destructor called by Ice" << std::endl;
}

AMateria	*Ice::clone( void ) const
{
	return (new Ice());
}

void	Ice::use( ICharacter &target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}