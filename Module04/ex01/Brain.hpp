
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	public:

		Brain();
		Brain( const Brain &brain);
		Brain	&operator=( const Brain &brain );
		virtual ~Brain();
	
	private:

		std::string		_ideas[100];
};

#endif