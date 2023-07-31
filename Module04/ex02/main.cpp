
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int	main( void )
{
	AAnimal	*animal;
	AAnimal	*nuvo;
	animal = new Dog();
	nuvo = new Cat();
	animal->makeSound();
	std::cout << animal->getType() << std::endl;
	nuvo->makeSound();
	delete (animal);
	delete (nuvo);
}