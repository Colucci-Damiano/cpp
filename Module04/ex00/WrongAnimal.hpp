
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
	public:

		WrongAnimal();
		WrongAnimal( const WrongAnimal &animal );
		WrongAnimal	&operator=( const WrongAnimal &animal );
		~WrongAnimal();

		void	makeSound( void ) const;
		std::string		getType( void ) const;
	
	protected:

		std::string		_type;
};

#endif