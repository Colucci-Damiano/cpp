
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie & Zombie::operator = (const Zombie &zombie)
{
	if (this != &zombie)
	{
		this->_name = zombie._name;
	}
	return (*this);
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " is dead" << std::endl ;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ":BraiiiiiiinnnzzzZ..." << std::endl;
}