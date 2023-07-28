
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>

class DiamondTrap : virtual public FragTrap, virtual  public ScavTrap
{
	public:

		DiamondTrap();
		DiamondTrap( const std::string name );
		DiamondTrap( const DiamondTrap &diamond );
		DiamondTrap	&operator=( const DiamondTrap &diamond );
		~DiamondTrap();
		void		whoAmI( void ) const;
		void		printStats( void ) const;
		using		ScavTrap::attack;

	private:

		std::string			_name;
		//using				FragTrap::_attackDamage;
};

#endif