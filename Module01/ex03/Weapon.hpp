
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	public:

		Weapon();
		Weapon(std::string type);
		~Weapon();
		Weapon(const Weapon &weapon);
		Weapon & operator = (const Weapon &weapon);

		const std::string&	getType( void ) const;
		void				setType(std::string type);

	private:

		std::string			_type;
};

#endif