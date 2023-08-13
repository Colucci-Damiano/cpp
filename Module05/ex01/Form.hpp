
#pragma once

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class	Form
{
	public:
		Form();
		Form( Form const & );
		Form&	operator=( Form const & );
		virtual ~Form();

		Form(std::string const &name, int const gradeSign, int const gradeExe );

		std::string		getName( void ) const;
		bool			getIsSigned( void ) const;
		int 			getGradeSign( void ) const;
		int 			getGradeExe( void ) const;

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();
				GradeTooLowException( std::string const & );
				virtual ~GradeTooLowException() throw();

				char const*	what( void ) const throw();
			private:
				std::string	_msg;
		};
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException();
				GradeTooHighException( std::string const & );
				virtual ~GradeTooHighException() throw();

				char const*	what( void ) const throw();
			private:
				std::string	_msg;
		};
		void			beSigned( Bureaucrat const &bur ) throw(Form::GradeTooLowException);
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeSign;
		int const			_gradeExe;

};

std::ostream&	operator<<( std::ostream& os, Form const &form );