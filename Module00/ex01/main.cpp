#include <iostream>
#include <string>
#include <list>

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
		std::cout << GREEN << "Inserisci un comando" << RESET << std::endl;
		std::cin >> command;
		if (!command.compare("ADD"))
			phoneBook.add();
		else if (!command.compare("SEARCH"))
			phoneBook.search();
		else if (!command.compare("EXIT"))
			phoneBook.set_Running(false);
		else
			std::cout << RED << command << " : opzione non valida!" \
			<< RESET << std::endl;
	}
	return (0);
}