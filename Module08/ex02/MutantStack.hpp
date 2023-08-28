
#pragma once

#include <deque>
#include <list>

//Class MutantStack

template<typename T, typename Container = std::deque<T>>
class	MutantStack
{
	public:
		MutantStack();
		MutantStack( MutantStack<T, Container> const & other );
		~MutantStack();
		MutantStack<T>&	operator=( MutantStack<T, Container> const & other );

		bool		empty( void ) const;
		size_t		size( void ) const;
		T &			top( void );
		T const &	top( void )const;
		void		push(T const & value);

		template<typename Args>
		void 		emplace( Args & args );

		void		pop();
		void		swap( MutantStack<T, Container> & other );

	private:
		size_t		_size;
};

//Relational operators overload

template <class T, class Container>
bool operator== (const MutantStack<T,Container>& lhs, const MutantStack<T,Container>& rhs);
template <class T, class Container>
bool operator!= (const MutantStack<T,Container>& lhs, const MutantStack<T,Container>& rhs);
template <class T, class Container>
bool operator<  (const MutantStack<T,Container>& lhs, const MutantStack<T,Container>& rhs);
template <class T, class Container>
bool operator<= (const MutantStack<T,Container>& lhs, const MutantStack<T,Container>& rhs);
template <class T, class Container>
bool operator>  (const MutantStack<T,Container>& lhs, const MutantStack<T,Container>& rhs);
template <class T, class Container>
bool operator>= (const MutantStack<T,Container>& lhs, const MutantStack<T,Container>& rhs);

// std::swap function overload

template <class T, class Container>
void swap (MutantStack<T,Container>& x, MutantStack<T,Container>& y);
