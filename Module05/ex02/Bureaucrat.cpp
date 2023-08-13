
#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

//*********************************************************************************//
//                        Bureaucrat exceptions nested classes                     //
//*********************************************************************************//

Bureaucrat::GradeTooHighException::GradeTooHighException( std::string const &msg ) : _msg(msg)
{

}

Bureaucrat::GradeTooLowException::GradeTooLowException( std::string const &msg) : _msg(msg)
{

}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{

}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{

}

char const*		Bureaucrat::GradeTooHighException::what() const throw()
{
	return( this->_msg.c_str() );
}

char const*		Bureaucrat::GradeTooLowException::what() const throw()
{
	return ( this->_msg.c_str() );
}

//*********************************************************************************//
//                                 Bureaucrat class                                //
//*********************************************************************************//

//Default constructor

Bureaucrat::Bureaucrat() : _name("<DefaultName>"), _grade(150)
{

}

//String constructor

Bureaucrat::Bureaucrat( const std::string &name, const int grade ) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Grade too high");
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Grade too low");
}

//Destructor

Bureaucrat::~Bureaucrat(){}

//Copy constructor

Bureaucrat::Bureaucrat( const Bureaucrat &bur )
{
	*this = bur;
}

//Copy assignment operator overload

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
	if (this->_grade <= 1)	
		throw Bureaucrat::GradeTooHighException("Increment of maximum grade");
	this->_grade--;
}

void		Bureaucrat::decrementGrade( void )
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException("Decrement of minimum grade");
	this->_grade++;
}

void		Bureaucrat::signForm( AForm &form ) const
{
	if (form.getIsSigned())
	{
		std::cout << *this << " couldn't sign " << form << " because it is already signed." << std::endl;
	}
	else if (form.getGradeSign() < this->getGrade())
	{
		std::cout << *this << " couldn't sign " << form << " because he has not the required grade." << std::endl;
	}
	else
	{
		std::cout << *this << " signed " << form << std::endl;
	}
	form.beSigned( *this );
}

//*********************************************************************************//
//                            << operator overload                                 //
//*********************************************************************************//

std::ostream	&operator<<( std::ostream &os, const Bureaucrat &bur)
{
	os << "\033[32m";
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	os << "\033[0m";
	return (os);
}