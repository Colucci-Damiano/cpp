
#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	Zombie	*rick;
	Zombie	morty("Morty");

	morty.announce();
	rick = new Zombie("Morty");
	rick->announce();
	delete (rick);
	return (0);
}