#ifndef POINT_HPP_
# define POINT_HPP_

# include <iostream>
# include "Fixed.hpp"


class Point {

private:
/* Attributes */
	Fixed const	_x;
	Fixed const	_y;
	/* cannot be copied b/c of const attributes */
	Point	operator=( Point const & rhs );

public:
/* Functions */
	Point( );
	Point( int const x, int const y );
	Point( Fixed const x, Fixed const y );
	Point( Point const & src );
	Point	operator-( Point const & rhs );
	~Point( );
	Fixed	getX( ) const;
	Fixed	getY( ) const;

};

std::ostream & operator<<( std::ostream & o, Point const & s );
#endif // POINT_HPP_
