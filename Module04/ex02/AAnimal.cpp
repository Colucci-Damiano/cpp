
#include "AAnimal.hpp"
#include <string>
#include <iostream>

// Default constructor

AAnimal::AAnimal()
{
	this->_type = "Animal";
	std::cout << "Default constructor called for class Animal" << std::endl;
}

// Copy constructor

AAnimal::AAnimal( const AAnimal &animal )
{
	if (this != &animal)
		*this = animal;
	std::cout << "Copy constructor called for class Animal" << std::endl;
}

// Copy assignment operator

AAnimal	&AAnimal::operator=( const AAnimal &animal )
{
	if (this != &animal)
	{
		this->_type = animal._type;
	}
	std::cout << "Copy assignment operator called for class Animal" << std::endl;
	return (*this);
}

// Default destructor

AAnimal::~AAnimal()
{
	std::cout << "Destructor called for class Animal" << std::endl;
}

void	AAnimal::makeSound( void ) const
{
	std::cout << "IM AN ANIMAAAAL" << std::endl;	
}

std::string		AAnimal::getType( void ) const
{
	return (this->_type);
}