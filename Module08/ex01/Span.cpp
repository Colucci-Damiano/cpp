
#include "Span.hpp"

#include <algorithm>
#include <limits>

//*********************************************************************************//
//                            Span class canonical form                            //
//*********************************************************************************//

Span::Span( unsigned int N ) : _maxSize( N ), _currentSize(0) {}

Span::Span( Span const & other )
{
	if (this != &other)
	{
		
	}
}

Span&	Span::operator=( Span const & other )
{
	if (this != &other)
	{

	}
	return (*this);
}

Span::~Span(){}

//*********************************************************************************//
//                            Span exception nested class                          //
//*********************************************************************************//

Span::MaxNumbersException::MaxNumbersException( std::string const & msg ) : _msg(msg){}

Span::MaxNumbersException::~MaxNumbersException() throw() {}

char const *	Span::MaxNumbersException::what() throw()
{
	return (this->_msg.c_str());
}


Span::NoSpanException::NoSpanException( std::string const & msg ) : _msg(msg){}

Span::NoSpanException::~NoSpanException() throw() {}

char const *	Span::NoSpanException::what() throw()
{
	return (this->_msg.c_str());
}

//*********************************************************************************//
//                            Span class member function                           //
//*********************************************************************************//

size_t	Span::getMaxSize() const
{
	return (this->_maxSize);
}

size_t	Span::getCurrentSize() const
{
	return (this->_vectorInt.size());
}

void			Span::addNumber(int const number)
{
	if (this->getCurrentSize() == _maxSize)
		throw (Span::MaxNumbersException("MaxNumbersReachedException"));
	this->_vectorInt.push_back( number );
}

int				Span::shortestSpan( void ) const
{
	if (this->getCurrentSize() <= 1)
		throw (Span::NoSpanException("NoSpanException"));

	int								minSpan = std::numeric_limits<int>::max();
	std::vector<int>				cpy(this->_vectorInt);

	std::sort(cpy.begin(), cpy.end());

	std::vector<int>::iterator		it = cpy.begin();
	std::vector<int>::iterator		end = cpy.end();
	do
	{
		minSpan = std::min(minSpan, *(it + 1) - *it);
		it++;
	}
	while (it + 1 != end);
	return (minSpan);	
}

int				Span::longestSpan( void ) const
{
	if (this->getCurrentSize() <= 1)
		throw(Span::NoSpanException("NoSpanException"));
	std::vector<int>	cpy(this->_vectorInt);
	std::sort(cpy.begin(), cpy.end());
	return (cpy.back() - *cpy.begin());
}