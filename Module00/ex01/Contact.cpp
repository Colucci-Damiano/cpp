
#include "Contact.hpp"
#include <iostream>
#include <sstream>

Contact::Contact(std::string fN, std::string lN, std::string nN, \
std::string pN, std::string dS) : _firstName(fN), _lastName(lN), \
_nickName(nN), _phoneNumber(pN), _darkestSecret(dS)
{
}

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
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

void		Contact::setFirstName(std::string name)
{
	this->_firstName = name;
}

void		Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void		Contact::setNickName(std::string nick)
{
	this->_nickName = nick;
}

void		Contact::setPhoneNumber(std::string phone)
{
	this->_phoneNumber = phone;
}

void		Contact::setDarkestSecret(std::string secret)
{
	this->_darkestSecret = secret;
}

std::string	Contact::resizeField(std::string field) const
{
	if (field.length() > 10)
	{
		field.resize(9);
		field.append(".");
	}
	else if (field.length() < 10)
		for (int i = (int)field.length(); i < 10; i++)
			field.append(" ");
	return (field);
}

void	Contact::displaySearchContact(int id) const
{
	std::stringstream	s;

	s << id;
	std::cout << "|";
	std::cout << this->resizeField((s.str()));
	std::cout << "|";
	std::cout << this->resizeField(this->getFirstName());
	std::cout << "|";
	std::cout << this->resizeField(this->getLastName());
	std::cout << "|";
	std::cout << this->resizeField(this->getNickname());
	std::cout << "|";
	std::cout << std::endl;
}

void	Contact::displayFullContact(void) const
{
	std::cout << std::endl;
	std::cout << "	First Name : " << this->getFirstName() << std::endl;
	std::cout << "	Last Name : " << this->getLastName() << std::endl;
	std::cout << "	Nickname : " << this->getNickname() << std::endl;
	std::cout << "	Phone number : " << this->getPhoneNumber() << std::endl;
	std::cout << "	Darkest secret : " << this->getDarkestSecret() << std::endl;
}