
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed( const Fixed & );
		Fixed( int const raw );
		Fixed( float const raw );
		Fixed	&operator=(const Fixed &fixed );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					_fixedValue;
		static const int	_fractBits;
};

std::ostream	&operator<<( std::ostream &os, const Fixed &fixed );

#endif