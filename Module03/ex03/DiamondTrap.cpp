
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

// Default constructor

DiamondTrap::DiamondTrap( void ) : ScavTrap(), FragTrap()
{
	std::cout << "Default constructor called for the new DiamondTrap" << std::endl;
}

// String Constructor

DiamondTrap::DiamondTrap( const std::string name ) : ScavTrap( name ), FragTrap( name )
{
	std::cout << "String constructor called for the new DiamondTrap " << name << std::endl;
}

// Copy constructor

DiamondTrap::DiamondTrap( const DiamondTrap &diamond)
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

	}
	return (*this);
}