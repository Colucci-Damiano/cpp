
#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::_debug( void ) const
{
	std::cout << "\033[34mI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\033[0m" << std::endl;
}

void	Harl::_info( void ) const
{
	std::cout << "\033[36mI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\033[0m" << std::endl;
}

void	Harl::_warning ( void ) const
{
	std::cout << "\033[93mI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\033[0m" << std::endl;
}

void	Harl::_error( void ) const
{
	std::cout << "\033[91mThis is unacceptable! I want to speak to the manager now.\033[0m" << std::endl;
}

void	Harl::complain( std::string level ) const
{
	void	(Harl::*funct[4]) (void) const = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	int		levels[4] = {level.compare("DEBUG"), level.compare("INFO"), level.compare("WARNING"), level.compare("ERROR")};
	for (size_t i = 0; i < 4; i++)
	{
		if (!levels[i])
			(this->*funct[i])();
	}
	
}