
#ifndef	CAT_HPP
# define CAT_HPP

class Cat : public Animal
{
	public:

		Cat();
		Cat( const Cat &cat );
		Cat	&operator=( const Cat &cat );
		~Cat();

		void			makeSound( void ) const;
};

#endif