
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm( std::string const & target )
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{

}

PresidentialPardonForm::~PresidentialPardonForm(){}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	AForm::execute( executor );
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}