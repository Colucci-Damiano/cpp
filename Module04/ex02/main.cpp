
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int	main( void )
{
	AAnimal	*dog;
	AAnimal	*cat;

	dog = new Dog();
	cat = new Cat();
	dog->makeSound();
	std::cout << dog->getType() << std::endl;
	cat->makeSound();
	std::cout << cat->getType() << std::endl;

	delete (dog);
	delete (cat);
}