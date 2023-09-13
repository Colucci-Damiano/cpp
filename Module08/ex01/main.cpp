
#include "Span.hpp"
#include <iostream>
#include <stdlib.h>
#include <ctime>

int	main( void )
{
	std::cout << "----Test1------" << std::endl;

	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try
	{
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "----Test2------" << std::endl;

	unsigned int	numbers = 10;

	Span	tenThousand(numbers);
	int		ran;

	std::srand(std::time(NULL));

	for (unsigned int i = 0; i < numbers; i++)
	{
		ran = std::rand() % 50;
		tenThousand.addNumber(ran);
	}

	try
	{
		std::cout << "Shortest Span: " << tenThousand.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << tenThousand.longestSpan() << std::endl;
	}
	catch( std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "----Test3------" << std::endl;

	unsigned int		N = 10;
	std::vector<int>	vec;
	Span				multiple(N);

	for(unsigned int i = 0; i < N; i++)
	{
		vec.push_back(std::rand() % 200);
	}

	std::vector<int>::iterator	it = vec.begin();
	std::vector<int>::iterator	end = vec.end();

	try
	{
		multiple.multipleAdd(it, end);
		std::cout << "Shortest Span: " << multiple.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << multiple.longestSpan() << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}