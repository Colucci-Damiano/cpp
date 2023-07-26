
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	public:
	
		ClapTrap( void );
		ClapTrap( const std::string name );
		~ClapTrap( void );
		ClapTrap( const ClapTrap &trap );
		ClapTrap	&operator=( const ClapTrap &trap );

		std::string	getName( void ) const;
		bool		checkStatus ( void ) const;
		void		attack( const std::string &target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );
	private:
		
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

};

#endif