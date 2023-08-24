
#include "Classes.hpp"
#include <iostream>

int	main( void )
{
	Base	*p = NULL;
	Base	*newP = NULL;

	p = generate();
	identify(p);

	newP = generate();
	if (newP)
		identify(dynamic_cast<Base &>(*newP));

	delete (p);
	delete (newP);
	return (0);
}