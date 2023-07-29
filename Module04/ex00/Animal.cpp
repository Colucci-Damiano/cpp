
#include "Animal.hpp"
#include <string>
#include <iostream>

// Default constructor

Animal::Animal()
{
	std::cout << "Default constructor called for Animal type : " << this->_type << std::endl;
	this->_type = "Animal";
}

// String constructor

Animal::Animal( const std::string &type )
{
	std::cout << "String constructor called for Animal type : " << this->_type << std::endl;
	this->_type = type;
}

// Copy constructor

Animal::Animal( const Animal &animal )
{
	if (this != &animal)
		*this = animal;
}

// Copy assignment operator

Animal	&Animal::operator=( const Animal &animal )
{
	if (this != &animal)
	{
		this->_type = animal._type;
	}
	return (*this);
}

// Default destructor

Animal::~Animal()
{
	std::cout << "Default destructor called for Animal type : " << this->_type << std::endl;
}

void	Animal::makeSound( void ) const
{
	std::cout << "IM AN ANIMAAAAL" << std::endl;	
}

std::string		Animal::getType( void ) const
{
	return (this->_type);
}