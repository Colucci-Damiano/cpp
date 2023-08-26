
#include "easyfind.hpp"

#include <iostream>
#include <list>
#include <vector>

int	main( void )
{
	//LIST TEST

	std::cout << "LIST TEST" << std::endl;
	std::list<int>		intList;
	int					toFind;

	toFind = 1232;
	intList.push_back(123);
	intList.push_back(12);
	intList.push_back(9789);
	intList.push_back(0);
	intList.push_back(3);

	std::list<int>::iterator	endList = intList.end();
	std::list<int>::iterator	found = easyfind(intList, toFind);

	if (found == endList)
		std::cout << "Integer " << toFind << " NOT FOUND in the list" << std::endl;
	else
		std::cout << "Integer " << toFind << " FOUND in the list" << std::endl;
	

	//VECTOR TEST

	std::cout << "VECTOR TEST" << std::endl;
	std::vector<int>	intVector;

	toFind = -6;
	intVector.push_back(12312);
	intVector.push_back(-12);
	intVector.push_back(-6);
	intVector.push_back(98);
	intVector.push_back(756);

	std::vector<int>::iterator	end = intVector.end();
	std::vector<int>::iterator	vecIt = easyfind(intVector, toFind);

	if (vecIt == end)
		std::cout << "Integer " << toFind << " NOT FOUND in the vector" << std::endl;
	else
		std::cout << "Integer " << toFind << " FOUND in the vector" << std::endl;
}