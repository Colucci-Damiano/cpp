
#ifndef	AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <string>

class ICharacter;

// Abstract class AMateria

class AMateria
{
	public:

		AMateria();
		AMateria( const std::string &type );
		virtual ~AMateria();

		const std::string	&getType( void ) const;

		virtual AMateria	*clone( void ) const = 0;
		virtual void		use( ICharacter &target );

	protected:

		std::string		_type;

};

#endif