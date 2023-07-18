
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class	HumanB
{
	public:

		HumanB(std::string name);
		HumanB(std::string name, Weapon weapon);
		~HumanB();
		HumanB(const HumanB &humanB);
		HumanB & operator =(const HumanB &humanB);

		void			attack(void) const;
		void			setWeapon(Weapon weapon);
	private:

		Weapon			_weapon;
		std::string		_name;
};

#endif