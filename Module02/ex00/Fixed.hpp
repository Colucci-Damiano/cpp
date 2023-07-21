
#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed & operator = (const Fixed &fixed);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	
	private:
		int					_fixedValue;
		static const int	_fractBits;
};

#endif