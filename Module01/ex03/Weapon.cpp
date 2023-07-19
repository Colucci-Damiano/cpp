
#include "Weapon.hpp"
#include <string>

Weapon::Weapon(){}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon(void){}

Weapon::Weapon(const Weapon &weapon)
{
	if (this != &weapon)
	{
		this->_type = weapon._type;
	}
}

Weapon & Weapon::operator = (const Weapon &weapon)
{
	if (this != &weapon)
	{
		this->_type = weapon._type;
	}
	return (*this);
}

const std::string&	Weapon::getType(void) const
{
	const std::string		&typeRef = this->_type;
	return (typeRef);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}