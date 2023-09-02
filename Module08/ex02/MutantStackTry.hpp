
#pragma once

#include <stack>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		
		MutantStack<T>(){}
		MutantStack<T>(MutantStack<T> const & other)
		{
			if (this != &other)
				*this = other;
		}
		virtual ~MutantStack<T>(){}
		MutantStack&	operator=(MutantStack<T> const & other)
		{
			if (this != &other)
			{
				this->c = other.c;
			}
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator					iterator;
		typedef typename std::stack<T>::container_type::const_iterator				const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator			reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator		const_reverse_iterator;

		iterator				begin( void )
		{
			return (this->c.begin());
		}
		const_iterator			cbegin( void ) const
		{
			return (this->c.cbegin());
		}
		iterator				end( void )
		{
			return (this->c.end());
		}
		const_iterator			cend( void ) const
		{
			return (this->c.cend());
		}
		reverse_iterator		rbegin( void )
		{
			return (this->c.rbegin());
		}
		const_reverse_iterator	crbegin( void ) const
		{
			return (this->c.crbegin());
		}
		reverse_iterator		rend( void )
		{
			return (this->c.rend());
		}
		const_reverse_iterator	crend( void ) const
		{
			return (this->c.crend());
		}
};