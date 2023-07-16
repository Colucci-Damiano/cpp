
#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <sstream>
#include <cstdlib>

PhoneBook::PhoneBook(void)
{
	this->_size = 8;
	this->_iterator = 0;
	this->_running = true;	
}

PhoneBook::~PhoneBook(void)
{
}

bool	PhoneBook::get_Running(void) const
{
	return (this->_running);
}

void	PhoneBook::set_Running(bool value)
{
	this->_running = value;
}

void	PhoneBook::help(void) const
{
	std::cout << std::endl << "\033[46mInsert a command for the PhoneBook\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[32mADD\033[0m	: add a contact in the phonebook" << std::endl;
	std::cout << "\033[32mSEARCH\033[0m	: search for a specific contact in the phonebook" << std::endl;
	std::cout << "\033[32mEXIT\033[0m	: close the phonebook" << std::endl;
	std::cout << std::endl;
}

std::string	PhoneBook::_instertField(std::string outputMess) const
{
	std::string	input;

	while (1)
	{
		std::cout << outputMess << std::endl;
		std::cout << ">>" ;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (input);
		if (input.length() == 0)
				std::cout << "\033[31mThe phonebook can't have empty fields\033[0m" << std::endl;
		else
			break ;
	}
	return (input);
}

std::string PhoneBook::_insertNumber(std::string outputMess) const
{
	std::string	input;

	while (1)
	{
		std::cout << outputMess << std::endl;
		std::cout << ">>" ;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (input);
		if (input.length() == 0)
				std::cout << "\033[31mThe phonebook can't have empty fields\033[0m" << std::endl;
		else if (!isNumber(input))
			std::cout << "\033[31mInstert only digit chars\033[0m" << std::endl;
		else
			break ;
	}
	return (input);
}

void	PhoneBook::add(void)
{
	Contact		contact;

	contact = this->_contacts[this->_iterator];
	contact.setFirstName(this->_instertField("Insert name"));
	contact.setLastName(this->_instertField("Inster last name"));
	contact.setNickName(this->_instertField("Insert nick name"));
	contact.setPhoneNumber(this->_insertNumber("Insert phone number"));
	contact.setDarkestSecret(this->_instertField("Insert your darkest secret 👹"));
	this->_contacts[this->_iterator] = contact;
	this->_incrementIterator();
}

int		PhoneBook::_insertIdSearch(void) const
{
	int				id;
	std::string		input;

	std::cout << "Insert a valid id contact [0-7]" << std::endl;
	do
	{
		std::cout << ">>" ;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (-1);
		if (input.length() == 0)
			std::cout << "The phonebook can't have empty fields" << std::endl;
		if (!isNumber(input))
			std::cout << "\033[31mInsert an integer\033[0m" << std::endl;
		else
		{
			id = std::atoi(input.c_str());
			if (id < 0 || id > 7)
				std::cout << "\033[31mInsert a value between 0 and 7\033[0m" << std::endl;
			else
				break ;
		}
	}
	while (1);
	return (id);
}

void	PhoneBook::search(void) const
{
	int		id;

	std::cout << "\033[4m";
	std::cout << "\033[36mPHONEBOOK\033[0m" << std::endl;
	std::cout << "\033[4m";
	std::cout << "|    ID    |   NAME   |LAST NAME | NICKNAME |" << std::endl;
	for(int i = 0; i < this->_size; i++)
	{
		this->_contacts[i].displaySearchContact(i);
	}
	std::cout << "\033[0m" << std::endl;
	id = this->_insertIdSearch();
	if (id < 0 || id > 7)
		return ;
	std::cout << std::endl;
	std::cout << "\033[4;33m" << "INFO\033[4;0m " << "of contact id : " << id << "\033[0m" << std::endl;
	this->_contacts[id].displayFullContact();
	std::cout << std::endl;
}

void	PhoneBook::_incrementIterator(void)
{
	this->_iterator += 1;
	this->_iterator = this->_iterator % this->_size;
}

bool	PhoneBook::isNumber(std::string str) const
{
	int			i;
	const char	*add;

	i = 0;
	add = str.c_str();
	if (add[i] == '-' || add[i] == '+')
		i++;
	while (add[i])
	{
		if (!isdigit(add[i]))
			return (false);
		i++;
	}
	return (true);
}
