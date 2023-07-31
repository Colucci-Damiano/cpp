
#include "AMateria.hpp"
#include <iostream>
#include <string>

// Default constructor

AMateria::AMateria()
{
	std::cout << "Default constructor called by AMateria" << std::endl;
}

// String constructor

AMateria::AMateria( const std::string &type )
{
	std::cout << "String constructor called by AMateria" << std::endl;
}

