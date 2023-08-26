
#include <iostream>
#include "Array.tpp"

#define N1 15
#define N2 20
#define N3 25

int	main()
{
	//TEST 1

	Array<float>	f(N1);

	//Filling array
	try
	{
		for (int i = 0; i < N1; i++)
		{
			f[i] = static_cast<float>(i) + 17.6f;
		}
	}
	catch(std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	//Testing constructor with unsigned int

	std::cout << "After construtor f(N1)" << std::endl;
	try
	{
		for(int i = 0; i < static_cast<int>(f.size()); i++)
		{
			std::cout << f[i] << std::endl;
		}
	}
	catch(std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	//Testing copy constructor

	Array<float>	cpyFloat( f );

	std::cout << "After copy constructor cpyFloat( f )" << std::endl;
	try
	{
		for (int i = 0; i < N1; i++)
		{
			std::cout << cpyFloat[i] << std::endl;
		}
	}
	catch(std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	//Testing copy assignment operator

	Array<float>		equal;

	equal = f;
	std::cout << "After copy assignment operator equal( f )" << std::endl;
	try
	{
		for (int i = 0; i < N1; i++)
		{
			std::cout << equal[i] << std::endl;
		}
	}
	catch(std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	
}