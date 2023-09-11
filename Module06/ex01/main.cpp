
#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <stdint.h>

int	main()
{
	//Test 1
	std::cout << "TEST1" << std::endl;
	Data		data;
	uintptr_t	raw = Serializer::serialize(&data);

	data.name = "Damiano";
	data.lastName = "Colucci";
	data.age = 24;

	std::cout	<< "Name: " << data.name
				<< " Last name: " << data.lastName
				<< " Age: " << data.age
				<< std::endl;

	Data	*ptr = Serializer::deserialize(raw);

	std::cout	<< "Name: " << ptr->name
				<< " Last name: " << ptr->lastName
				<< " Age: " << ptr->age
				<< std::endl;

	/*	TEST 2	*/

	std::cout << "TEST2" << std::endl;
	Data	newData;

	newData.name = "Giorgio";
	newData.lastName = "Bruno";
	newData.age = 21;

	Data*	test = Serializer::deserialize(Serializer::serialize(&newData));
	std::cout << &newData << " is the original\n" << test << " is the result of conversion" << std::endl;
}