
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>

class Character : public ICharacter
{
	public:

		Character();
		Character( const std::string &name);
		Character( const Character &character );
		Character	&operator=( const Character &character );
		~Character();

		const std::string		&getName( void ) const;
		void					equip( AMateria *m );
		void					unequip( int idx );
		void					use( int idx, ICharacter &target );
	
	private:

		std::string				_name;
		static const int		_numberOfSlots;
		AMateria				**_slots;
};

#endif