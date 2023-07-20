
#include "Harl.hpp"
#include <iostream>
#include <string>

#define GREEN "\033[92m"
#define RESET "\033[0m"

int	main( void )
{
	Harl		harl;
	std::string level;
	while (1)
	{
		std::cout << "Insert : " << GREEN << " | DEBUG | INFO | WARNING | ERROR |" << RESET << std::endl;
		std::cout << ">>" ;
		std::getline(std::cin, level, '\n');
		if (std::cin.eof())
			break ;
		harl.complain(level);
	}
	return (0);
}