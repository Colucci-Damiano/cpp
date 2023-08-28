
#pragma once

#include "MutantStack.hpp"
#include <deque>
#include <string>

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(){}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const & other )
{

}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(){}


template <typename T, typename Container>
MutantStack<T, Container> &		MutantStack<T, Container>::operator=( MutantStack<T, Container> const & other )
{
	
}


template<typename T, typename Container>
size_t	MutantStack<T, Container>::size() const
{

}