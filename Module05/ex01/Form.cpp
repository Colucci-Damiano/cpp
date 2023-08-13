
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>

//*********************************************************************************//
//                                 Form class                                      //
//*********************************************************************************//

//Default constructor

Form::Form() : _name("<DefaultFormName>"), _isSigned( false ), _gradeSign( 150 ), _gradeExe( 150 )
{

}

//Parameters constructor

Form::Form(std::string const &name, int const gradeSign, int const gradeExe )
: _name( name ), _gradeSign( gradeSign ), _gradeExe( gradeExe )
{
	if (gradeSign < 1 || gradeExe < 1)
		throw(Form::GradeTooHighException("Grade too high"));
	else if (gradeSign > 150 || gradeExe > 150)
		throw(Form::GradeTooLowException("Grade too low"));
}

// Copy constructor

Form::Form( Form const &form ) : _name( form._name), _isSigned(form._isSigned), \
_gradeSign( form._gradeSign), _gradeExe(form._gradeExe)
{

}

// Copy assignment operator overload

Form&	Form::operator=( Form const &form )
{
	if (this != &form)
	{

	}
	return ( *this );
}

//Destructor

Form::~Form(){}

std::string		Form::getName( void ) const
{
	return (this->_name);
}

bool			Form::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int				Form::getGradeSign( void ) const
{
	return (this->_gradeSign);
}

int				Form::getGradeExe( void ) const
{
	return (this->_gradeExe);
}

void			Form::beSigned( Bureaucrat const &bur ) throw(Form::GradeTooLowException)
{
	if (this->_gradeSign >= bur.getGrade())
		this->_isSigned = true;
	else
		throw( Form::GradeTooLowException("Grade too low to sign"));
}

//*********************************************************************************//
//                        Form exceptions nested classes                           //
//*********************************************************************************//

Form::GradeTooHighException::GradeTooHighException( std::string const &msg ) : _msg(msg){}

Form::GradeTooLowException::GradeTooLowException( std::string const &msg ) : _msg(msg){}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

char const*		Form::GradeTooHighException::what() const throw()
{
	return( this->_msg.c_str() );
}

char const*		Form::GradeTooLowException::what() const throw()
{
	return ( this->_msg.c_str() );
}

//*********************************************************************************//
//                            << operator overload                                 //
//*********************************************************************************//

std::ostream&	operator<<( std::ostream &os, Form const &form )
{
	os << "\033[34m" 
	   << "Form name: " 
	   << form.getName() 
	   << ". Grade to sign: " 
	   << form.getGradeSign() 
	   << ", grade to execute: " 
	   << form.getGradeExe() 
	   << "." 
	   << "\033[0m";
	return (os);
}
