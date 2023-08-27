
#pragma once

#include <string>
#include <exception>
#include <vector>

class Span
{
	public:
		Span(unsigned int N);
		Span( Span const & );
		virtual ~Span();
		Span&	operator=( Span const & span );

		class MaxNumbersException : public std::exception
		{
			public:
				MaxNumbersException(std::string const & msg);
				virtual ~MaxNumbersException() throw();
				
				virtual char const *	what() throw();
			private:
				std::string		_msg;
		};

		class NoSpanException : public std::exception
		{
			public:
				NoSpanException(std::string const & msg);
				virtual ~NoSpanException() throw();
				
				virtual char const *	what() throw();
			private:
				std::string		_msg;
		};

		size_t	getMaxSize() const;
		size_t	getCurrentSize() const;
		void	addNumber( int const number );
		int		shortestSpan( void ) const;
		int		longestSpan( void ) const;

	private:
		Span();

		unsigned int			_maxSize;
		unsigned int			_currentSize;
		std::vector<int>		_vectorInt; // Which container should i use?
};