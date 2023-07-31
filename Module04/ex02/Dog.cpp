
#include "AAnimal.hpp"
#include "Dog.hpp"
#include <string>
#include <iostream>

// Default constructor

Dog::Dog() : AAnimal()
{
	this->_brain = new Brain();
	this->_type = "Dog";
	std::cout << "Default constructor called for class Dog" << std::endl;
}

// Copy constructor

Dog::Dog( const Dog &dog ) : AAnimal( dog )
{
	if (this != &dog)
		*this = dog;
	std::cout << "Copy constructor called for class Dog" << std::endl;
}

// Copy assignment operator

Dog		&Dog::operator=( const Dog &dog )
{
	if (this != &dog)
	{
		delete(this->_brain);
		this->_brain = new Brain( *dog._brain );
		*(this->_brain) = *(dog._brain);
		this->_type = dog._type;
	}
	std::cout << "Copy assignment operator called for class Dog" << std::endl;
	return (*this);
}

// Destructor

Dog::~Dog()
{
	delete (this->_brain);
	std::cout << "Destructor called for class Dog" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "WOFWOF" << std::endl;
}