
#include "Character.hpp"
#include <string>
#include <iostream>

const int	Character::_numberOfSlots = 4;
const int	Character::_droppedItemsMax = 10;

// Default constructor

Character::Character() : _name("<DefaultCharacterName>"), _equipedSlots(0), _droppedItems(0)
{
	_slots = new AMateria*[_numberOfSlots];
	_dropped = new AMateria*[_droppedItemsMax];

	for (int i = 0; i < _numberOfSlots; i++)
		_slots[i] = NULL;
	for (int i = 0; i < _droppedItemsMax; i++)
		_dropped[i] = NULL;
	std::cout << "Default constructor called by Character" << std::endl;
}

// String constructor

Character::Character( const std::string &name ) : _name( name ), _equipedSlots(0), _droppedItems(0)
{
	_slots = new AMateria*[_numberOfSlots];
	_dropped = new AMateria*[_droppedItemsMax];

	for (int i = 0; i < _numberOfSlots; i++)
		_slots[i] = NULL;
	for (int i = 0; i < _droppedItemsMax; i++)
		_dropped[i] = NULL;
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
		this->_name = character._name;
		// Clearing all the slots of 'this' object
		for(int i = 0; i < _numberOfSlots; i++)
		{
			if (this->_slots[i])
			{
				delete (this->_slots[i]);
				this->_slots[i] = NULL;
			}
		}
		//Clear dropped items of 'this' object
		for (int i = 0; i < _droppedItemsMax; i++)
		{
			if (this->_dropped[i])
			{
				delete( this->_dropped[i] );
				this->_dropped[i] = NULL;
			}
		}
		//Cloning slots of character into 'this'
		for( int i = 0; i < _numberOfSlots; i++)
		{
			if (character._slots[i])
			{
				this->_slots[i] = character._slots[i]->clone();
			}
		}
		//Cloning dropped items of character into 'this'
		for (int i = 0; i < _droppedItemsMax; i++)
		{
			if (character._dropped[i])
			{
				this->_dropped[i] = character._dropped[i]->clone();
			}
		}
		//Copying dropped and equipement AMaterias
		this->_equipedSlots = character._equipedSlots;
		this->_droppedItems = character._droppedItems;
	}
	std::cout << "Copy assignment operator called by Character" << std::endl;
	return (*this);
}

// Destructor

Character::~Character()
{
	for(int i = 0; i < Character::_numberOfSlots; i++)
	{
		if (this->_slots[i])
		{
			delete(this->_slots[i]);
			_slots[i] = NULL;
		}
	}
	delete [] _slots;
	for(int i = 0; i < Character::_droppedItemsMax; i++)
	{
		if (this->_dropped[i])
		{
			delete(this->_dropped[i]);
			_dropped[i] = NULL;
		}
	}
	delete [] _dropped;
	std::cout << "Destructor called by Character" << std::endl;
}

const std::string	&Character::getName( void ) const
{
	return (this->_name);
}

void				Character::equip( AMateria *m )
{
	if (this->_equipedSlots >= Character::_numberOfSlots || !m)
		return ;
	for( int i = 0; i < _numberOfSlots; i++)
	{
		if (_slots[i] == NULL)
		{
			_slots[i] = m;
			break ;
		}
	}
}

void				Character::unequip( int idx )
{
	if (this->_droppedItems >= Character::_droppedItemsMax)
		return ;
	if ( idx < 0 || idx >= _numberOfSlots)
		return ;
	this->_dropped[_droppedItems] = this->_slots[idx];
	this->_dropped++;
	this->_slots[idx] = NULL;
}
 
void				Character::use( int idx, ICharacter &target )
{
	if ( idx < 0 || idx >= _numberOfSlots)
		return ;
	if (this->_slots[idx])
		this->_slots[idx]->use(target);
}