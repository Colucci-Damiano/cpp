
#include "Weapon.hpp"
#include <string>

Weapon::Weapon(){}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon(void){}

const std::string&	Weapon::getType(void) const
{
	const std::string&		typeRef = this->_type;
	return (typeRef);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}