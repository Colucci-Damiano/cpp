
#include "Cure.hpp"
#include <iostream>

// Default constructor

Cure::Cure() : AMateria()
{
	this->_type = "cure";
	std::cout << "Default constructor calle by Cure" << std::endl;
}

// Copy constructor

Cure::Cure( const Cure &cure )
{
	if (this != &cure)
		*this = cure;
}

// Copy assignment operator

Cure	&Cure::operator=( const Cure &cure )
{
	if (this != &cure)
	{
	}
	return (*this);
}

// Destructor

Cure::~Cure()
{
	std::cout << "Destructor called by Cure" << std::endl;
}

AMateria	*Cure::clone( void ) const
{
	return (new Cure( *this ));
}

void	Cure::use( ICharacter &target )
{
	std::cout	<< "* heals " << target.getName() 
				<< "'s wounds *" << std::endl;
}