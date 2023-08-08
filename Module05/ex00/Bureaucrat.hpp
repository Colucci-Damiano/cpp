
#pragma once

#include <string>

class Bureaucrat
{
	public:

		Bureaucrat();
		Bureaucrat( const std::string &name, const int grade );
		Bureaucrat( const Bureaucrat &bur );
		Bureaucrat	&operator=( const Bureaucrat &bur );
		~Bureaucrat();

		std::string	getName( void  ) const;
		int			getGrade( void ) const;

		void		incrementGrade( void );
		void		decrementGrade( void );

		class GradeTooLowException : public std::exception
		{
			virtual const char	*what() const noexcept;
		};
		class GradeTooHighException : public std::exception
		{
			virtual const char	*what() const noexcept;
		};

	private:

		const std::string	_name;
		int					_grade;

};

// operator overload <<