
#ifndef	AMATERIA_HPP
# define AMATEIRA_HPP

# include "ICharacter.hpp"
# include <string>

// Abstract class AMateria

class AMateria
{
	public:

		AMateria();
		AMateria( const std::string &type );
		~AMateria();

		const std::string	&getType( void ) const;

		virtual AMateria	*clone( void ) const = 0;
		virtual void		use( ICharacter &target );

	protected:


};

#endif