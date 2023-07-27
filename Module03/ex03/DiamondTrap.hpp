
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:

		DiamondTrap();
		DiamondTrap( const std::string name );
		DiamondTrap( const DiamondTrap &diamond );
		DiamondTrap	&operator=( const DiamondTrap &diamond );
		~DiamondTrap();

	private:

		std::string		_name;
};

#endif