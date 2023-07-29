
#ifndef	DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:

		Dog();
		Dog( const std::string &type );
		Dog( const Dog &cat );
		Dog	&operator=( const Dog &cat );
		~Dog();

		void 	makeSound( void ) const;

	private:

		Brain	*brain;
};

#endif