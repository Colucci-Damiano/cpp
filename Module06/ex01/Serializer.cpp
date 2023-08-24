
#include "Serializer.hpp"
#include "Data.hpp"
#include <stdint.h>

uintptr_t	Serializer::serialize(Data* ptr)
{
	void*	p = reinterpret_cast<void*>(ptr);

	uintptr_t	u = (uintptr_t)p;
	return (u);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	void*	p = (void *)raw;

	return (reinterpret_cast<Data*>(p));
}