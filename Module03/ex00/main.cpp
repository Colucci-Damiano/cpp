
#include "ClapTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap	robo("ROBOCOP");
	ClapTrap	mecha("MECHA");

	robo.attack(mecha.getName());
	robo.beRepaired(1);
	robo.takeDamage(12);
	robo.attack("BOT");
	for(int i = 0; i < 20; i++)
	{
		mecha.beRepaired(1);
	}
}