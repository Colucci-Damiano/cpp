
#pragma once

#include <string>

class Bureaucrat;

class	AForm
{
	public:
		AForm();
		AForm( AForm const & );
		AForm&	operator=( AForm const & );
		virtual ~AForm();

		AForm(std::string const &name, int const gradeSign, int const gradeExe );

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
		class FormNotSignedException : public std::exception
		{
			public:
				FormNotSignedException( std::string const & msg );
				virtual ~FormNotSignedException() throw();

				char const*	what( void ) const throw();
			private:
				FormNotSignedException();
				std::string		_msg;

		};
		void			beSigned( Bureaucrat const &bur );

		virtual void	execute( Bureaucrat const & executor ) const = 0 ;

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeSign;
		int const			_gradeExe;

};

std::ostream&	operator<<( std::ostream& os, AForm const &form );