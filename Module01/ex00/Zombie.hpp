
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie
{
	public:

		Zombie(void);											//Default constructor
		Zombie(std::string name);
		~Zombie(void);											//Copy constructor
		Zombie(const Zombie &zombie);						//Destructor
		Zombie & operator = (const Zombie &zombie);	//Copy assignment operator

		void			announce(void) const;

	private:

		std::string		_name;
};

#endif