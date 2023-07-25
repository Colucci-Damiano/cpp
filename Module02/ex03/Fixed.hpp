
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

		Fixed	&operator=( const Fixed &fixed );
		bool	operator>( const Fixed &fixed ) const;
		bool	operator<( const Fixed &fixed ) const;
		bool	operator>=( const Fixed &fixed ) const;
		bool	operator<=( const Fixed &fixed ) const;
		bool	operator==( const Fixed &fixed ) const;
		bool	operator!=( const Fixed &fixed ) const;
		Fixed	operator+( const Fixed &fixed ) const;
		Fixed	operator-( const Fixed &fixed ) const;
		Fixed	operator*( const Fixed &fixed ) const;
		Fixed	operator/( const Fixed &fixed ) const;
		Fixed	operator++( void );
		Fixed	operator++( int );	//postfix
		Fixed	operator--( void );
		Fixed	operator--( int );	//postfix

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed		&min( Fixed &f1, Fixed &f2 );
		static const Fixed	&min( const Fixed &f1, const Fixed &f2 );
		static Fixed		&max( Fixed &f1, Fixed &f2 );
		static const Fixed	&max( const Fixed &f1, const Fixed &f2 );

	private:
		int					_fixedValue;
		static const int	_fractBits;
};

std::ostream	&operator<<( std::ostream &os, const Fixed &fixed );

#endif