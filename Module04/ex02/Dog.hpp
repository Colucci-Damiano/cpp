
#ifndef	DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:

		Dog();
		Dog( const Dog &cat );
		Dog	&operator=( const Dog &cat );
		virtual ~Dog();

		void 	makeSound( void ) const;

	private:

		Brain	*_brain;
};

#endif