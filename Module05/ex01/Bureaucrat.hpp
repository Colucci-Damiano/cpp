
#pragma once

#include "Form.hpp"
#include <string>
#include <ostream>

class Form;

class Bureaucrat
{
	public:

		Bureaucrat();
		Bureaucrat( const std::string &name, const int grade );
		Bureaucrat( const Bureaucrat &bur );
		Bureaucrat	&operator=( const Bureaucrat &bur );
		virtual ~Bureaucrat();

		std::string	getName( void  ) const;
		int			getGrade( void ) const;

		void		incrementGrade( void );
		void		decrementGrade( void );

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
		void		signForm( Form &form ) const;
		
	private:

		const std::string		_name;
		int						_grade;
		

};

// operator << overload

std::ostream	&operator<<( std::ostream & os, const Bureaucrat & bur);
