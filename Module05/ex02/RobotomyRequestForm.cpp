
#include "RobotomyRequestForm.hpp"
#include <iostream>


RobotomyRequestForm::RobotomyRequestForm( std::string const & target )
: AForm("ShrubberyCreationForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void		RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	AForm::checkForm( executor );
	std::cout << "* SOME DRILLING NOISES *" << std::endl;
	std::cout << "* SOME DRILLING NOISES *" << std::endl;
	std::cout << "* SOME DRILLING NOISES *" << std::endl;
	std::cout << this->_target << " has been robotomized successfully 50% of the time!" << std::endl;
}