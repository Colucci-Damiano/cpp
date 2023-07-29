#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main( void )
{
	Animal	animals = new Animal[100];

	for (int i = 0; i < 100; i++)
	{
		if (i < 50)
			new (&animals[i]) Dog();
		else
			new(&animals[i]) Cat();
	}
	for(int i = 0; i < 100; i++)
		delete &(animals[i]);
}
