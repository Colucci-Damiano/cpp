
#include "Classes.hpp"
#include <iostream>
#include <cstdlib>
#include <exception>

Base::~Base(){};

A::A(){};
A::~A(){};

B::B(){};
B::~B(){};

C::C(){};
C::~C(){};


Base*	generate( void )
{
	int		r;

	srand(time(NULL));
	r = rand() % 3;
	switch (r)
	{
		case 0:
			std::cout << "Generated A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Generated B" << std::endl;
			return (new B());
		case 2:
			std::cout << "Generated C" << std::endl;
			return (new C());
		default:
			break;
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (p == NULL)
		std::cout << "Warning: NULL pointer" << std::endl;
	else if (dynamic_cast<A *>(p))
		std::cout << "Actual type of pointer is A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Actual type of pointer is B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Actual type of pointer is C" << std::endl;
	else
		std::cout << "Type of pointer unknown" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "Actual type of reference is A" << std::endl;
		return ;
	}
	catch(std::exception & e)
	{

	}

	try
	{
		dynamic_cast<B &>(p);
		std::cout << "Actual type of reference is B" << std::endl;
		return ;
	}
	catch(std::exception & e)
	{

	}

	try
	{
		dynamic_cast<C &>(p);
		std::cout << "Actual type of pointer is C" << std::endl;
		return ;
	}
	catch(std::exception & e)
	{

	}

	std::cout << "Unknown type of reference" << std::endl;
}