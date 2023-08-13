
#pragma once

#include "AForm.hpp"
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm( std::string const &target );
		ShrubberyCreationForm( ShrubberyCreationForm const &other );
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm&	operator=( ShrubberyCreationForm const &other );

		void	execute( Bureaucrat const & executor ) const;

	private:
		ShrubberyCreationForm();
		std::string		_target;
};