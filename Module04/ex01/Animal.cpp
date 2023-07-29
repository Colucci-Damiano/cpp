
#include "Animal.hpp"
#include <string>
#include <iostream>

// Default constructor

Animal::Animal()
{
	this->_type = "Animal";
	std::cout << "Default constructor called for " << this->_type << std::endl;
}

// Copy constructor

Animal::Animal( const Animal &animal )
{
	if (this != &animal)
		*this = animal;
	std::cout << "Copy constructor called for " << this->_type << std::endl;
}

// Copy assignment operator

Animal	&Animal::operator=( const Animal &animal )
{
	if (this != &animal)
	{
		this->_type = animal._type;
	}
	std::cout << "Copy assignment operator called for " << this->_type << std::endl;
	return (*this);
}

// Default destructor

Animal::~Animal()
{
	std::cout << "Default destructor called for " << this->_type << std::endl;
}

void	Animal::makeSound( void ) const
{
	std::cout << "IM AN ANIMAAAAL" << std::endl;	
}

std::string		Animal::getType( void ) const
{
	return (this->_type);
}