
#include "HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name)
{
	this->_name = name;
}

HumanB::~HumanB(void){}

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attack with their " << this->_weapon.getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = weapon;
}