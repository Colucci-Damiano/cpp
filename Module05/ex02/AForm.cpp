
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

//*********************************************************************************//
//                                 AForm class                                      //
//*********************************************************************************//

//Default constructor

AForm::AForm() : _name("<DefaultAFormName>"), _isSigned( false ), _gradeSign( 150 ), _gradeExe( 150 )
{

}

//Parameters constructor

AForm::AForm(std::string const &name, int const gradeSign, int const gradeExe )
: _name( name ), _gradeSign( gradeSign ), _gradeExe( gradeExe )
{
	this->_isSigned = false;
	if (gradeSign < 1 || gradeExe < 1)
		throw(AForm::GradeTooHighException("Grade too high"));
	else if (gradeSign > 150 || gradeExe > 150)
		throw(AForm::GradeTooLowException("Grade too low"));
}

// Copy constructor

AForm::AForm( AForm const &form ) : _name( form._name), _isSigned(form._isSigned), \
_gradeSign( form._gradeSign), _gradeExe(form._gradeExe)
{

}

// Copy assignment operator overload

AForm&	AForm::operator=( AForm const &form )
{
	if (this != &form)
	{

	}
	return ( *this );
}

//Destructor

AForm::~AForm(){}

std::string		AForm::getName( void ) const
{
	return (this->_name);
}

bool			AForm::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int				AForm::getGradeSign( void ) const
{
	return (this->_gradeSign);
}

int				AForm::getGradeExe( void ) const
{
	return (this->_gradeExe);
}

void			AForm::beSigned( Bureaucrat const &bur )
{
	if (this->_gradeSign >= bur.getGrade())
		this->_isSigned = true;
	else
		throw( AForm::GradeTooLowException("Grade too low to sign"));
}

//*********************************************************************************//
//                        AForm exceptions nested classes                           //
//*********************************************************************************//

AForm::GradeTooHighException::GradeTooHighException( std::string const &msg ) : _msg(msg){}

AForm::GradeTooLowException::GradeTooLowException( std::string const &msg ) : _msg(msg){}

AForm::FormNotSignedException::FormNotSignedException( std::string const & msg ) : _msg(msg){}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

AForm::FormNotSignedException::~FormNotSignedException() throw () {}

char const*		AForm::GradeTooHighException::what() const throw()
{
	return( this->_msg.c_str() );
}

char const*		AForm::GradeTooLowException::what() const throw()
{
	return ( this->_msg.c_str() );
}

const char*		AForm::FormNotSignedException::what( void ) const throw()
{
	return ( this->_msg.c_str() );
}

void	AForm::execute( Bureaucrat const & executor ) const 
{
	if (this->getIsSigned() == false)
		throw ( FormNotSignedException("Form not signed"));
	if (getGradeExe() < executor.getGrade())
		throw ( GradeTooLowException("Executor grade too low"));
}

//*********************************************************************************//
//                            << operator overload                                 //
//*********************************************************************************//

std::ostream&	operator<<( std::ostream &os, AForm const &form )
{
	os << "\033[34m" 
	   << "AForm name: " 
	   << form.getName() 
	   << ". Grade to sign: " 
	   << form.getGradeSign() 
	   << ", grade to execute: " 
	   << form.getGradeExe() 
	   << "." 
	   << "\033[0m";
	return (os);
}
