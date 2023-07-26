
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

// Default constructor

FragTrap::FragTrap( void ) : ClapTrap()
{
	this->_name = "bot";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 3;
	std::cout << "Default constructor called for FragTrap bot" << std::endl;
}

// String Constructor

FragTrap::FragTrap( const std::string name ) : ClapTrap( name )
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 3;
	std::cout << "String constructor called for FragTrap " << this->_name << std::endl;
}

// Copy constructor

FragTrap::FragTrap( const FragTrap &frag )
{
	if (this != &frag)
	{
		*this = frag;
	}
}

// Copy assignment operator overload

FragTrap	&FragTrap::operator=( const FragTrap &frag )
{
	if (this != &frag)
	{
		this->_name = frag._name;
		this->_hitPoints = frag._hitPoints;
		this->_energyPoints = frag._energyPoints;
		this->_attackDamage = frag._attackDamage;
	}
	return (*this);
}

// Destructor

FragTrap::~FragTrap()
{
	std::cout << "Destructor called for FragTrap " << this->_name << std::endl;
}

void	FragTrap::highFivesGuys( void ) const
{
	std::cout << "Unit " << this->_name <<" says: HIGH FIVE GUYS! 👋" << std::endl;
}