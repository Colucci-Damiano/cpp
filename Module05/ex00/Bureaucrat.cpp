
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("<DefaultName>"), _grade(150)
{

}

Bureaucrat::Bureaucrat( const std::string &name, const int grade ) : _name(name), _grade(grade)
{
	if (grade < 1 || grade > 150)
		throw "Invalid grade range";
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat( const Bureaucrat &bur )
{
	*this = bur;
}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat &bur )
{
	if (this != &bur)
	{
		this->_grade = bur._grade;
	}
	return (*this);
}

std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

void		Bureaucrat::incrementGrade( void )
{
	//throws exception
	if (this->_grade == 1)	
		throw "Maximum grade exception!";
	this->_grade++;
}

void		Bureaucrat::decrementGrade( void )
{
	//throws exception
	if (this->_grade == 150)
		throw "Minimum grade exception";
	this->_grade--;
}