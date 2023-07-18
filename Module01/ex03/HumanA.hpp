
#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class	HumanA
{
	public:

		HumanA(std::string name, Weapon weapon);
		~HumanA();
		HumanA(const HumanA &humanA);
		HumanA & operator = (const HumanA &humanA);

		void	attack(void) const;

	private:

		Weapon			_weapon;
		std::string		_name;
};

#endif