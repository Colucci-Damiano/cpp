
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <ostream>

int	main( void )
{
	try
	{
		Bureaucrat	scemo("Scemotto", -8);
	}
	catch ( std::exception &e )
	{
		std::cout << "Exception thrown : " << e.what() <<std::endl;
	}
	catch (...)
	{
		std::cout << "Default exception thrown";
	}

	try
	{
		Bureaucrat	dritto("Dritto", 76);
		for (int i = 0; i < 79; i++)
			dritto.incrementGrade();
	}
	catch ( std::exception &e )
	{
		std::cout << "Exception thrown : " << e.what() <<std::endl;
	}
	catch (...)
	{
		std::cout << "Default exception thrown";
	}
	
	try
	{
		Bureaucrat	gigio("gigio", 80);
		std::cout << gigio << std::endl;
	}
	catch ( std::exception &e )
	{
		std::cout << "Exception thrown : " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Default exception thrown" << std::endl;
	}

	std::cout << "Fine" << std::endl;

	return (0);
}