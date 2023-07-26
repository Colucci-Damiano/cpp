
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap
{
	public:

		FragTrap( void );
		FragTrap( const std::string name );
		FragTrap( const FragTrap &frag );
		FragTrap	&operator=( const FragTrap &frag );
		~FragTrap( void );

		void		highFivesGuys( void ) const ;
};

#endif