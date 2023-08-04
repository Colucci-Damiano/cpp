
#include "Brain.hpp"
#include <iostream>

// Default constructor

Brain::Brain()
{
	std::cout << "Default constructor called for class Brain" << std::endl;
}

// Copy constructor

Brain::Brain( const Brain &brain )
{
	std::cout << "Copy constructor called for class Brain" << std::endl;
	if (this != &brain)
		*this = brain;
}

// Copy assignment operator

Brain	&Brain::operator=( const Brain &brain )
{
	std::cout << "Copy assignment operator called for class Brain" << std::endl;
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = brain._ideas[i];
		}
	}
	return (*this);
}

// Destructor

Brain::~Brain()
{
	std::cout << "Destructor called for class Brain" << std::endl;
}