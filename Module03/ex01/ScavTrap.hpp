
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

		ScavTrap();
		ScavTrap( const ScavTrap &scav );
		ScavTrap	&operator=( const ScavTrap &scav );
		~ScavTrap();
	
	private:

		
};

#endif