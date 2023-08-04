
#include "MateriaSource.hpp"
#include <iostream>

const int	MateriaSource::_slotsMax = 4;

// Default constructor

MateriaSource::MateriaSource()
{
	this->_slots = new AMateria*[MateriaSource::_slotsMax];
	for (int i = 0; i < MateriaSource::_slotsMax; i++)
		_slots[i] = NULL;
	std::cout << "Default constructor called by MateriaSource" << std::endl;
}

// Copy constructor

MateriaSource::MateriaSource( const MateriaSource &mSource )
{
	if (this != &mSource)
	{
		*this = mSource;
	}
	std::cout << "Copy constructor called by MateriaSource" << std::endl;
}

// Copy assignment operator

MateriaSource	&MateriaSource::operator=( const MateriaSource &mSource )
{
	if (this != &mSource)
	{
		for (int i = 0; i < MateriaSource::_slotsMax; i++)
		{
			if (this->_slots[i])
			{
				delete(this->_slots[i]);
				this->_slots[i] = NULL;
			}
			if (mSource._slots[i])
			{
				_slots[i] = mSource._slots[i]->clone();
			}
		}
	}
	std::cout << "Copy assignment operator called by MateriaSource" << std::endl;
	return (*this);
}

// Destructor

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < MateriaSource::_slotsMax; i++)
	{
		if (this->_slots[i])
		{
			delete(this->_slots[i]);
			this->_slots[i] = NULL;
		}
	}
	delete [] (_slots);
	std::cout << "Default constructor called by MateriaSource" << std::endl;
}

void		MateriaSource::learnMateria( AMateria *m )
{
	for (int i = 0; i < MateriaSource::_slotsMax; i++)
	{
		if (this->_slots[i] == NULL)
		{
			this->_slots[i] = m->clone();
			break ;
		}
	}
}

AMateria	*MateriaSource::createMateria( const std::string &type )
{
	for(int i = 0; i < MateriaSource::_slotsMax; i++)
	{
		if (this->_slots[i])
		{
			if (this->_slots[i]->getType() == type)
			{
				return (this->_slots[i]->clone());
			}
		}
	}
	return (0);
}