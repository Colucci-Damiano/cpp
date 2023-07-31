
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal
{
	public:

		AAnimal();
		AAnimal( const AAnimal &animal );
		AAnimal	&operator=( const AAnimal &animal );
		virtual ~AAnimal();

		virtual void			makeSound( void ) const = 0;
		virtual std::string		getType( void ) const;
	
	protected:

		std::string		_type;
};

#endif