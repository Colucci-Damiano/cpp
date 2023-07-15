
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
		phoneBook.help();
		std::cout << ">>\033[32m";
		std::cin >> command;
		std::cout << "\033[0m" << std::endl;
		if (std::cin.eof())
		{
			std::cout << "EOF signal received. Restarting input." << std::endl;

                // Clear the fail state
                std::cin.clear();

                // Ignore remaining characters in the input buffer
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
		}
		else if (!command.compare("ADD"))
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