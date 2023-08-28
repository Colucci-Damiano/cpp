
#pragma once

#include <deque>
#include <list>
#include <string>

//Class MutantStack

template<typename T>
class	MutantStack
{
	public:
		MutantStack(){}
		MutantStack( MutantStack<T> const & other )
		{
			if (this != &other)
			{

			}
		}
		~MutantStack(){}
		MutantStack<T>&	operator=( MutantStack<T> const & other )
		{
			if (this != &other)
			{

			}
			return (*this);
		}

		bool		empty( void ) const
		{
			return (this->_stackContainer.empty());
		}
		size_t		size( void ) const
		{
			return (this->_stackContainer.size());
		}
		T &			top( void )
		{

		}
		T const &	top( void )const;
		void		push(T const & value);

		template<typename Args>
		void 		emplace( Args & args );

		void		pop();
		void		swap( MutantStack<T> & other );

	private:
		typedef std::deque<T>::iterator		mutantIterator_t;
		std::deque<T>						_stackContainer;
};

// Relational operators overload

template <class T, class Container>
bool operator== (const MutantStack<T>& lhs, const MutantStack<T>& rhs);
template <class T, class Container>
bool operator!= (const MutantStack<T>& lhs, const MutantStack<T>& rhs);
template <class T, class Container>
bool operator<  (const MutantStack<T>& lhs, const MutantStack<T>& rhs);
template <class T, class Container>
bool operator<= (const MutantStack<T>& lhs, const MutantStack<T>& rhs);
template <class T, class Container>
bool operator>  (const MutantStack<T>& lhs, const MutantStack<T>& rhs);
template <class T, class Container>
bool operator>= (const MutantStack<T>& lhs, const MutantStack<T>& rhs);

// std::swap function overload

template <class T, class Container>
void swap (MutantStack<T>& x, MutantStack<T>& y);

#include "MutantStack.tpp"