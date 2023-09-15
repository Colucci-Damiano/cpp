
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:

		Point( void );
		Point( float const f1, float const f2 );
		Point( Point const &point );
		Point	&operator=( Point const &point );
		~Point( void );

		const Fixed		getX( void ) const;
		const Fixed		getY( void ) const;

		bool			operator==( Point const &point) const;
		void			printPoint( void ) const;

	private:

		Fixed const	_x;
		Fixed const	_y;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif