
#pragma once

#include <exception>
#include <stdint.h>

template<typename T>
class	Array
{
	public:
		Array() : _size(0), _array(NULL) {}

		Array( unsigned int const n ) : _size(static_cast<size_t>(n)), _array(new T[n]())
		{
		}

		Array( Array<T> const & other ) : _size(0), _array(NULL)
		{
			if (this != &other)
				*this = other;
		}
		virtual ~Array()
		{
			if (this->_array)
				delete [] (this->_array);
		} 

		Array<T>&	operator=( Array<T> const & other)
		{
			if  (this != &other)
			{
				if (this->_array)
					delete [] (this->_array);
				this->_array = new T[other.size()];
				for(size_t i = 0; i < other.size(); i++)
				{
					this->_array[i] = other._array[i];
				}
				this->_size = other.size();
			}
			return (*this);
		}
		T&	operator[]( int index )
		{
			if (index >= static_cast<int>(this->size()) || index < 0)
				throw(std::runtime_error("Out of index"));
			return (_array[index]);
		}

		size_t		size( void ) const
		{
			return (this->_size);
		}

	private:
		size_t		_size;
		T*			_array;
};