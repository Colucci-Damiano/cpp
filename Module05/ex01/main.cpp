
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main( void )
{
	try
	{
		Bureaucrat	luca("Luca", 2);
		Form		form("Modulo", 20, 50);

		std::cout << luca << std::endl;
		std::cout << form << std::endl;

		std::cout << luca << "is new here " << std::endl;
		
		luca.signForm(form);

		Bureaucrat	giovanni("Gio", 80);
		Form		taxes("taxes", 40, 40);

		giovanni.signForm( taxes );
	}
	catch( Bureaucrat::GradeTooHighException &e )
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
	catch( Bureaucrat::GradeTooLowException &e )
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
	catch ( Form::GradeTooLowException &e )
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
	catch( Form::GradeTooHighException & e )
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
	return (0);
}