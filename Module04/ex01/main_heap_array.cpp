#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int	main( void )
{
	const int	size = 100;
	Animal	**animals = new Animal*[size];

	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < size; i++)
	{
		delete (animals[i]);
	}

	delete [] animals;
}