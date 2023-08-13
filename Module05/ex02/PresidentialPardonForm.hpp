
#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm( std::string const &target );
		PresidentialPardonForm( PresidentialPardonForm const &other );
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm&	operator=( PresidentialPardonForm const &other );

		void	execute( Bureaucrat const & executor ) const;

	private:
		PresidentialPardonForm();
		std::string		_target;
};