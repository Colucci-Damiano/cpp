#include "Contact.hpp"
#include <iostream>

Contact::Contact(std::string fN, std::string lN, std::string nN, \
std::string pN, std::string dS) : _firstName(fN), _lastName(lN), \
_nickName(nN), _phoneNumber(pN), _darkestSecret(dS)
{
	std::cout << "Constructor initialization list called" << std::endl;
}

Contact::Contact(void)
{
	std::cout << "Constructor called for Contact" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Destructor called for Contact" << std::endl;
}

std::string		Contact::getFirstName(void) const
{	
	return (this->_firstName);
}

std::string		Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string		Contact::getNickname(void) const
{
	return (this->_nickName);
}

std::string		Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string		Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}
