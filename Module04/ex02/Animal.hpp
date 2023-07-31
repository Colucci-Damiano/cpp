
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	public:

		Animal();
		Animal( const Animal &animal );
		Animal	&operator=( const Animal &animal );
		virtual ~Animal();

		virtual void	makeSound( void ) const;
		std::string		getType( void ) const;
	
	protected:

		std::string		_type;
};

#endif