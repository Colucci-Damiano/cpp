
#include "iter.hpp"
#include <iostream>

void	printChar( char c )
{
	std::cout << c ;
}

void	incrementNumber(int & n)
{
	n = n + 1;
}

template<typename T>
void	incrementGeneric(T & value)
{
	value += 1;
}

int	main( void )
{
	//TEST 1
	std::cout << "TEST 1" << std::endl;
	std::string		s("arrayOfChar");

	iter(s.c_str(), s.length(), &printChar);
	std::cout << std::endl;

	//TEST 2
	std::cout << "TEST 2" << std::endl;
 	int				n[15];

	for (int i = 0; i < 15; i++)
	{
		n[i] = i;
	}

	for(int i = 0; i < 15; i++)
	{
		std::cout << n[i] << "|";
	}
	std::cout << std::endl;

	iter(&n[0], 15, &incrementNumber);

	for(int i = 0; i < 15; i++)
	{
		std::cout << n[i] << "|";
	}
	std::cout << std::endl;

	//TEST 3
	std::cout << "TEST 3" << std::endl;
	float	f[10];

	for (int i = 0; i < 10; i++)
	{
		f[i] = 17.1f + i;
	}

	for(int i = 0; i < 10; i++)
	{
		std::cout << f[i] << "|";
	}
	std::cout << std::endl;

	iter(&f[0], 10, incrementGeneric<float>);

	for(int i = 0; i < 10; i++)
	{
		std::cout << f[i] << "|";
	}
	std::cout << std::endl;
}
