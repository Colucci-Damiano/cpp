
#include <array>
#include <iostream>
#include <exception>

int	main()
{
	std::array<int, 10>		array;

	try
	{
		for(int i = 0; i < array.size() + 1; i++)
		{
			array[i] = i;
		}	
	}
	catch(std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}