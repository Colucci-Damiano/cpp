
#pragma once

#include <algorithm>

//It returns a reference to the iterator pointing at toFind value.
//If toFind is missing in the container T, end iterator is returned.

template<typename T>
typename T::iterator	easyfind( T & container, int toFind )
{
	typename T::iterator	it = container.begin();
	typename T::iterator	end = container.end();

	while (it != end)
	{
		if (*it == toFind)
			return (it);
		it++;
	}
	return (end);
}