
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

// Default constructor

AMateria::AMateria() : _type("<Default Type>")
{
	std::cout << "Default constructor called by AMateria" << std::endl;
}

// String constructor

AMateria::AMateria( const std::string &type ) : _type( type )
{
	std::cout << "String constructor called by AMateria" << std::endl;
}

// Destructor

AMateria::~AMateria()
{
	std::cout << "Destructor called by AMateria" << std::endl;
}

const std::string	&AMateria::getType( void ) const
{
	return (this->_type);
}

void	AMateria::use( ICharacter &target )
{
	std::cout << "<Default action> on " << target.getName() << std::endl;
}
