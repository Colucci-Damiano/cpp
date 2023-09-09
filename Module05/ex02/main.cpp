
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main( void )
{
	try
	{
		std::cout << std::endl;
		std::cout << "[TEST1]" << std::endl;
		std::cout << std::endl;
		Bureaucrat				morganFreeman("Morgan Freeman", 1);
		ShrubberyCreationForm	shForm("homeMorgan");
		morganFreeman.signForm( shForm );
		shForm.execute( morganFreeman );
	}
	catch( std::exception & e )
	{
		std::cout << "[Block 1 exception]" << std::endl;
		std::cout << "Exception : " << e.what() << std::endl;
	}
	
	try
	{
		std::cout << std::endl;
		std::cout << "[TEST2]" << std::endl;
		std::cout << std::endl;
		Bureaucrat				noob("MR noob", 20);
		ShrubberyCreationForm	shForm("noobTrees");

		noob.signForm( shForm );
		shForm.execute( noob );
	}
	catch ( std::exception & e )
	{
		std::cout << "[Block 2 exception]" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl;
		std::cout << "[TEST3]" << std::endl;
		std::cout << std::endl;
		Bureaucrat		gio("gio", 2);

		ShrubberyCreationForm		shForm("gio trees");
		PresidentialPardonForm		prForm(gio.getName());
		RobotomyRequestForm			roForm(gio.getName());

		gio.signForm(shForm);
		gio.signForm(prForm);
		gio.signForm(roForm);

		shForm.execute( gio );
		prForm.execute( gio );
		roForm.execute( gio );
	}
	catch ( std::exception & e )
	{
		std::cout << "[Block 3 exception]" << std::endl;
		std::cout << "Exception : " << e.what() << std::endl;
	}
}