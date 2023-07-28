
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

// Default constructor

DiamondTrap::DiamondTrap( void )
{
	this->_name = "<DefaultName>";
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "Default constructor called for the new DiamondTrap " << this->_name << std::endl;
}

// String Constructor

DiamondTrap::DiamondTrap( const std::string name )
{
	this->_name = name;
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "String constructor called for the new DiamondTrap " << this->_name << std::endl;
}

// Copy constructor

DiamondTrap::DiamondTrap( const DiamondTrap &diamond )
{
	if (this != &diamond)
	{
		*this = diamond;
	}
}

// Copy assignment operator overload

DiamondTrap		&DiamondTrap::operator=( const DiamondTrap &diamond )
{
	if (this != &diamond)
	{
		this->_name = diamond._name;
		this->ClapTrap::_name = diamond.ClapTrap::_name;
		this->_hitPoints = diamond._hitPoints;
		this->_energyPoints = diamond._energyPoints;
		this->_attackDamage = diamond._attackDamage;
	}
	return (*this);
}

// Destructor

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called for DiamondTrap " << this->_name << std::endl;
}

void	DiamondTrap::printStats( void ) const
{
	std::cout << "oRIGINAL frag attack : " << FragTrap::_attackDamage << std::endl;
	std::cout << "\033[32m";
	std::cout << "Name : " << this->_name << std::endl;
	std::cout << "HitPoints : " << this->_hitPoints << std::endl;
	std::cout << "EnergyPoints : " << this->_energyPoints << std::endl;
	std::cout << "AttackDamage : " << this->_attackDamage << std::endl;
	std::cout << "\033[0m";
}

void	DiamondTrap::whoAmI( void )const
{
	std::cout << "My name is : " << this->_name << " and my ClapTrap name is : " << this->ClapTrap::_name << std::endl;
}