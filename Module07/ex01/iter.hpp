
#pragma once

#include <cstdlib>
#include <iostream>

template<typename T, typename S>
void	iter(T * array, size_t size, void func(S))
{
	if ( !array )
	{
		std::cerr << "Error: NULL pointer in iter function" << std::endl;
		return ;
	}
	for(size_t i = 0; i < size; i++)
	{
		func(array[i]);
	}
}