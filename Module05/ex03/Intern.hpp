
#pragma once

#include "AForm.hpp"
#include <string>

class Intern
{
	public:
		Intern();
		Intern( Intern const & );
		Intern&	operator=( Intern const & );
		~Intern();

		class FormNotFoundException : public std::exception
		{
			public:
				FormNotFoundException( std::string const & target );
				virtual ~FormNotFoundException() throw();
				char const *	what() const throw();
			private:
				FormNotFoundException();
				std::string	_msg;
		};

		AForm*	makeForm( std::string const & name, std::string const & target ) const ;
	private:
		AForm*			(*_generateForm[3])( std::string const & target );
		std::string		_nameForm[3];
};