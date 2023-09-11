
#pragma once

#include <string>

class ScalarConverter
{
	public:

		typedef enum en_types
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			UNKNOWN
		}types;

		static bool		isChar( std::string const & type );
		static bool		checkNotDiplayableChar( int i );
		static bool		isInteger( std::string const & type );
		static bool		checkIntOverflow( std::string const & type );
		static bool		isFloatDouble( std::string const & type );

		static types	detectType( std::string const & type );

		static void		fromChar( std::string const & type );
		static void		fromInt( std::string const & type );
		static void		fromFloat( std::string const & type );
		static void		fromDouble( std::string const & type );

		static void		convert( std::string const & type );

	private:

		ScalarConverter();
		ScalarConverter( ScalarConverter const & other );
		~ScalarConverter();
		ScalarConverter&	operator=( ScalarConverter const & other );	
};