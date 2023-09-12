
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
				
				char const *	what() const throw();
			private:
				std::string		_msg;
		};

		class NoSpanException : public std::exception
		{
			public:
				NoSpanException(std::string const & msg);
				virtual ~NoSpanException() throw();
				
				char const *	what() const throw();
			private:
				std::string		_msg;
		};

		size_t	getMaxSize( void ) const;
		size_t	getCurrentSize( void ) const;

		void	addNumber( int const number );

		template<typename T>
		void	multipleAdd(typename T::iterator start, typename T::iterator end)
		{
			
		}

		int		shortestSpan( void ) const;
		int		longestSpan( void ) const;

	private:
		Span();

		unsigned int			_maxSize;
		std::vector<int>		_vectorInt; // Which container should i use?
};