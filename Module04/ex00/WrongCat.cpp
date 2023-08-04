
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

// Default constructor

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "Default constructor called for " << this->_type << std::endl;
}

// Copy constructor

WrongCat::WrongCat( const WrongCat &wrongCat ) : WrongAnimal( wrongCat )
{
	if (this != &wrongCat)
		*this = wrongCat;
	std::cout << "Copy constructor called for " << this->_type << std::endl;
}

// Copy assignment operator

WrongCat		&WrongCat::operator=( const WrongCat &WrongCat )
{
	if (this != &WrongCat)
		this->_type = WrongCat._type;
	std::cout << "Copy assignment operator called for " << this->_type << std::endl;
	return (*this);
}

// Default constructor

WrongCat::~WrongCat()
{
	std::cout << "Destructor called for " << this->_type << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "WRONG MEOW" << std::endl;
}