
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ScavTrap	a;
	ScavTrap	b("mdip");

	b.attack("mdip");
	for (int i = 0; i < 100; i++)
		b.beRepaired(10);
	b.guardGate();
}