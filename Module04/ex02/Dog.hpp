
#ifndef	DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	public:

		Dog();
		Dog( const Dog &cat );
		Dog	&operator=( const Dog &cat );
		virtual ~Dog();

		void 			makeSound( void ) const;

	private:

		Brain	*_brain;
};

#endif