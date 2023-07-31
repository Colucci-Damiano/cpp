
#ifndef	CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	public:

		Cat();
		Cat( const Cat &cat );
		Cat	&operator=( const Cat &cat );
		virtual ~Cat();

		void			makeSound( void ) const;

	private:

		Brain		*_brain;
};

#endif