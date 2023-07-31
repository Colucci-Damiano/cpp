
#include "Character.hpp"
#include <string>
#include <iostream>

const int	Character::_numberOfSlots = 4;

// Default constructor

Character::Character() : _name("<DefaultCharacterName>")
{
	_slots = new AMateria*[_numberOfSlots];
	for (int i = 0; i < _numberOfSlots; i++)
	{
		_slots[i] = NULL;
	}
	std::cout << "Default constructor called by Character" << std::endl;
}

// String constructor

Character::Character( const std::string &name ) : _name( name )
{
	_slots = new AMateria*[_numberOfSlots];
	for (int i = 0; i < _numberOfSlots; i++)
	{
		_slots[i] = NULL;
	}
	std::cout << "String constructor called by Character" << std::endl;
}

// Copy constructor

Character::Character( const Character &character )
{
	if (this != &character)
	{
		*this = character;		
	}
	std::cout << "Copy constructor called by Character" << std::endl;
}

// Copy assignment operator

Character	&Character::operator=( const Character &character )
{
	if (this != &character)
	{
	}
	std::cout << "Copy assignment operator called by Character" << std::endl;
	return (*this);
}

Character::~Character()
{
	std::cout << "Destructor called by Character" << std::endl;
}

const std::string	&Character::getName( void ) const
{
	return (this->_name);
}

void				Character::equip( AMateria *m )
{
	// HOW ??
}