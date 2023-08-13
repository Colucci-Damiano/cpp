
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <string>
#include <iostream>

//Constructor
Intern::Intern()
{
	this->_generateForm[0] = &ShrubberyCreationForm::generate;
	this->_generateForm[1] = &PresidentialPardonForm::generate;
	this->_generateForm[2] = &RobotomyRequestForm::generate;
	this->_nameForm[0] = "shrubbery creation";
	this->_nameForm[1] = "presidential pardon";
	this->_nameForm[2] = "robotomy request";
}

//Copy Constructor
Intern::Intern( Intern const & other )
{
	( void )other;
}

//Copy assignment operator overload
Intern&	Intern::operator=( Intern const & other )
{
	( void )other;
	return ( *this );
}

//Destructor
Intern::~Intern(){}

Intern::FormNotFoundException::FormNotFoundException( std::string const & msg)
: _msg(msg)
{

}

Intern::FormNotFoundException::~FormNotFoundException() throw() {}

char const*		Intern::FormNotFoundException::what() const throw()
{
	return (this->_msg.c_str());
}

AForm*	Intern::makeForm( std::string const & name, std::string const & target ) const
{
	AForm	*newForm = NULL;
	std::string	parse;

	parse = name;
	for( unsigned int i = 0; i < name.length(); i++)
		parse[i] = std::tolower(name[i]);

	for (int i = 0; i < 3; i++)
	{
		if (parse.compare(_nameForm[i]) == 0)
		{
			newForm = _generateForm[i]( target );
			std::cout << "Intern creates " << *newForm;
			return (newForm);
		}
	}

	if (newForm == NULL)
		throw (FormNotFoundException("Form not found"));

	return (0);
}