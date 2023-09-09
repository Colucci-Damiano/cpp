
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <string>
#include <iostream>

int	main( void )
{
	//TEST1
	try
	{
		Intern		someRandomIntern;
		AForm*		rrf;
		Bureaucrat	max("Max", 1);
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		max.signForm( *rrf );
		rrf->execute( max );

		delete(rrf);
	}
	catch( std::exception & e )
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	//TEST2
	try
	{
		AForm		*newForm;
		Intern		marco;
		Bureaucrat	luca("Luca", 1);

		newForm = marco.makeForm("PRESIDENTIAL PARDon", "Luca");
		std::cout << "arrivo" << std::endl;
		luca.signForm( *newForm );
		newForm->execute( luca );

		delete(newForm);
	}
	catch( std::exception & e )
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}
