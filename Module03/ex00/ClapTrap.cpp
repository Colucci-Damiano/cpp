
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

// Default constructor

ClapTrap::ClapTrap( void ) : _name("Bot"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor of ClapTrap called with default name " << std::endl;
}

// Constructor string

ClapTrap::ClapTrap( const std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor called for ClapTrap " << name << std::endl;
}

// Destructor

ClapTrap::~ClapTrap( void )
{
	std::cout << "Destructor called for ClapTrap " << this->_name << std::endl;
}

// Copy constructor

ClapTrap::ClapTrap( const ClapTrap &trap )
{
	if (this != &trap)
	{
		*this = trap;
	}
	std::cout << "Copy constructor called for ClapTrap " << this->_name << std::endl;
}

// Copy assignment operator

ClapTrap	&ClapTrap::operator=( const ClapTrap &trap)
{
	if (this != &trap)
	{
		this->_name = trap._name;
		this->_hitPoints = trap._hitPoints;
		this->_energyPoints = trap._energyPoints;
		this->_attackDamage = trap._attackDamage;
	}
	return (*this);
}

std::string	ClapTrap::getName( void ) const
{
	return (this->_name);
}

bool	ClapTrap::checkStatus( void ) const
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

void	ClapTrap::attack( const std::string &target )
{
	if (this->checkStatus())
		return ;
	this->_energyPoints--;
	std::cout	<< "ClapTrap " 
				<< this->_name << " attacks " 
				<< target << ", causing "
				<< this->_attackDamage 
				<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->checkStatus())
		return ;
	if ( this->_hitPoints >= amount )
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	std::cout	<< "Unit " << this->_name << " has taken "
				<< amount << " points of damage!" << std::endl;
	if (this->_hitPoints == 0)
		std::cout << "Unit " << this->_name << " just died" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->checkStatus())
		return ;
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout	<< "ClapTrap " << this->_name
				<< " repairs himshelf by " << amount 
				<< " hit points!" << std::endl;
}