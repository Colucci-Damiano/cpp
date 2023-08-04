#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

// Default constructor

WrongAnimal::WrongAnimal()
{
	this->_type = "WrongAnimal";
	std::cout << "Default constructor called for " << this->_type << std::endl;
}

// Copy constructor

WrongAnimal::WrongAnimal( const WrongAnimal &animal )
{
	if (this != &animal)
		*this = animal;
	std::cout << "Copy constructor called for " << this->_type << std::endl;
}

// Copy assignment operator

WrongAnimal	&WrongAnimal::operator=( const WrongAnimal &animal )
{
	if (this != &animal)
	{
		this->_type = animal._type;
	}
	std::cout << "Copy assignment operator called for " << this->_type << std::endl;
	return (*this);
}

// Default destructor

WrongAnimal::~WrongAnimal()
{
	std::cout << "Default destructor called for " << this->_type << std::endl;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "IM AN ANIMAAAAL" << std::endl;	
}

std::string		WrongAnimal::getType( void ) const
{
	return (this->_type);
}