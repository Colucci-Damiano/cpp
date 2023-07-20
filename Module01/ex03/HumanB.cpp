
#include "HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

HumanB::~HumanB(void){}

void	HumanB::attack(void) const
{
	const	std::string	type = this->_weapon->getType();
	std::cout << this->_name << " attack with their " << type << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}