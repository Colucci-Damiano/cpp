
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : virtual public ClapTrap
{
	public:

		ScavTrap();
		ScavTrap( const std::string name );
		ScavTrap( const ScavTrap &scav );
		ScavTrap	&operator=( const ScavTrap &scav );
		~ScavTrap();

		std::string	getName( void ) const;
		bool		checkStatus ( void ) const;
		void		attack( const std::string &target );
		void		guardGate( void ) const;


};

#endif