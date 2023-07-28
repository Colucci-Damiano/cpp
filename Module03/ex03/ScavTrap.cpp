
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

// Default constructor

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "bot";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Default constructor called for ScavTrap " << this->_name << std::endl;
}

// Constructor string

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	_name = name;
	ScavTrap::_hitPoints = 100;
	ScavTrap::_energyPoints = 50;
	ScavTrap::_attackDamage = 20;
	std::cout << "Constructor string called for ScavTrap " << this->_name << std::endl;
}

// Destructor

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called for ScavTrap " << this->_name << std::endl;
}

// Copy constructor

ScavTrap::ScavTrap( const ScavTrap &scav )
{
	if (this != &scav)
	{
		*this = scav;
	}
	std::cout	<< "Copy constructor called for ScavTrap "
				<< this->_name << std::endl;
}

// Copy assignment operator

ScavTrap	&ScavTrap::operator=( const ScavTrap &scav)
{
	if (this != &scav)
	{
		this->_name = scav._name;
		this->_hitPoints = scav._hitPoints;
		this->_energyPoints = scav._energyPoints;
		this->_attackDamage = scav._attackDamage;
	}
	return (*this);
}

bool	ScavTrap::checkStatus( void ) const
{
	if (this->_hitPoints == 0)
	{
		std::cout	<< this->_name 
					<< " is broken, DON'T TOUCH IT!" << std::endl;
		return (true);
	}
	if (this->_energyPoints == 0)
	{
		std::cout	<< "No energy for unit " 
					<< this->_name
					<< std::endl;
		return (true);
	}
	return (false);
}

void	ScavTrap::attack( const std::string &target )
{
	if (this->checkStatus())
		return ;
	this->_energyPoints--;
	std::cout	<< "ScavTrap " 
				<< this->_name << " attacks " 
				<< target << ", causing "
				<< this->_attackDamage 
				<< " points of damage!" << std::endl;
}

void	ScavTrap::guardGate( void ) const
{
	std::cout << "The unit " << this->_name << " is on Gate keeper mode now" << std::endl;
}