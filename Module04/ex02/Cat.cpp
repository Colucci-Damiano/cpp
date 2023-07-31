
#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

// Default constructor

Cat::Cat() : Animal()
{
	this->_brain = new Brain();
	this->_type = "Cat";
	std::cout << "Default constructor called for class Cat" << std::endl;
}

// Copy constructor

Cat::Cat( const Cat &cat ) : Animal( cat )
{
	if (this != &cat)
		*this = cat;
	std::cout << "Copy constructor called for class Cat" << std::endl;
}

// Copy assignment operator

Cat		&Cat::operator=( const Cat &cat )
{
	if (this != &cat)
	{
		delete(this->_brain);
		this->_brain = new Brain( *cat._brain );
		*(this->_brain) = *(cat._brain);
		this->_type = cat._type;
	}
	std::cout << "Copy assignment operator called for class Cat" << std::endl;
	return (*this);
}

// Default constructor

Cat::~Cat()
{
	delete (this->_brain);
	std::cout << "Destructor called for class Cat" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "MEOW" << std::endl;
}