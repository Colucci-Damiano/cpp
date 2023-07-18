
#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	const Zombie	morty("Morty");
	Zombie*	rick = NULL;
	Zombie*	carl = NULL;
	Zombie	cloneMorty(morty);

	std::cout << "Real Morty" << std::endl;
	morty.announce();

	rick = new Zombie("rick");
	rick->announce();
	delete (rick);

	std::cout << "Mortys clone" << std::endl;
	cloneMorty.announce();

	carl = newZombie("Carl");
	carl->announce();

	randomChump("Brand");
	delete (carl);
	return (0);
}