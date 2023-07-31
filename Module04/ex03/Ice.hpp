#ifndef Ice_HPP
# define Ice_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public:

		Ice();
		Ice( const Ice &ice );
		Ice	&operator=( const Ice &ice );
		~Ice();

		AMateria	*clone( void ) const;
		void		use( ICharacter &target );
};

#endif