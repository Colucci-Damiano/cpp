#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
	this->_size = 0;
	this->_running = true;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called for PhoneBook" << std::endl;	
}

void	PhoneBook::add(void)
{
	std::cout << "Added" << std::endl;
}

void	PhoneBook::search(void) const
{
	std::cout << "Searching...." << std::endl;
}

void	PhoneBook::exit(void)
{
	set_Running(false);
}

bool	PhoneBook::get_Running(void) const
{
	return (this->_running);
}

void	PhoneBook::set_Running(bool value)
{
	this->_running = value;
}