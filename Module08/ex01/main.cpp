
#include "Span.hpp"
#include <iostream>
#include <stdlib.h>
#include <ctime>

int	main( void )
{
	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;


	unsigned int	numbers = 10;

	Span	tenThousand(numbers);
	int		ran;

	std::srand(std::time(NULL));

	for (unsigned int i = 0; i < numbers; i++)
	{
		ran = std::rand() % 5000000;
		std::cout << ran << std::endl; 
		tenThousand.addNumber(ran);
	}

	std::cout << "Shortest Span: " << tenThousand.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << tenThousand.longestSpan() << std::endl;

	return (0);
}