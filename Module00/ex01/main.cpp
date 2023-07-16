
#include <iostream>
#include <string>
#include <list>
#include <limits>

#include "Contact.hpp"
#include "PhoneBook.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

int	main()
{
	PhoneBook	phoneBook;
	std::string	command;

	while (phoneBook.get_Running())
	{
		if (std::cin.eof())
			break ;
		phoneBook.help();
		std::cout << ">>\033[32m";
		std::getline(std::cin, command);
		std::cout << "\033[0m" << std::endl;
		if (!command.compare("ADD"))
			phoneBook.add();
		else if (!command.compare("SEARCH"))
			phoneBook.search();
		else if (!command.compare("EXIT"))
			phoneBook.set_Running(false);
		else
			std::cout << "Invlaid option : " << RED << command << RESET << std::endl;
	}
	return (0);
}