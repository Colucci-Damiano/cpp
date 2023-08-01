
# include "AMateria.hpp"
# include "Character.hpp"
# include "Cure.hpp"
# include "Ice.hpp"
# include "MateriaSource.hpp"

int	main( void )
{
	Character	*damiano = new Character("Damiano");
	Character	*mbozzi = new Character("Bozzi");
	AMateria	*ice = new Ice();

	damiano->equip(ice);
	delete(ice);
	*mbozzi = *damiano;

	delete (damiano);
	delete (mbozzi);

	return (0);
}