#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
	this->_size = 0;
	this->_iterator = 0;
	this->_running = true;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called for PhoneBook" << std::endl;	
}

void	PhoneBook::add(void)
{ 
	this->incrementIterator();
	std::cout << "Now im considering iterator = " << this->_iterator << std::endl;
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

void	PhoneBook::incrementIterator(void)
{
	this->_iterator += 1;
	this->_iterator = this->_iterator % 8;
}

bool	PhoneBook::get_Running(void) const
{
	return (this->_running);
}

void	PhoneBook::set_Running(bool value)
{
	this->_running = value;
}