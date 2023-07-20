
#include "Harl.hpp"
#include <string>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl	harl;
		std::string	level = av[1];

		harl.complain(level);
	}
}