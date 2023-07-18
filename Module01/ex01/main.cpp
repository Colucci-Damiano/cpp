
#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	int		n = 10;
	Zombie*	horde = NULL;

	horde = zombieHorde(n, "Patrick");
	for (int i = 0; i < n; i++)
	{
		std::cout << "Zombie " << i << " is:  " << std::endl;
		horde[i].announce();
	}
	delete [] (horde);
	return (0);
}