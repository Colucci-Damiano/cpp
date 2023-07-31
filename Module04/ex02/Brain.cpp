
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
	if (this != &brain)
		*this = brain;
	std::cout << "Copy constructor called for class Brain" << std::endl;
}

// Copy assignment operator

Brain	&Brain::operator=( const Brain &brain )
{
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = brain._ideas[i];
		}
	}
	std::cout << "Copy assignment operator called for class Brain" << std::endl;
	return (*this);
}

// Destructor

Brain::~Brain()
{
	std::cout << "Destructor called for class Brain" << std::endl;
}