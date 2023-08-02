
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:

		MateriaSource();
		MateriaSource( const MateriaSource &matereiaSource );
		MateriaSource	&operator=( const MateriaSource &materiaSource );
		~MateriaSource();

		void		learnMateria( AMateria *m );
		AMateria	*createMateria( const std::string &type );
	
	private:

		AMateria			**_slots;
		static const int	_slotsMax;
};

#endif