#include "Point.hpp"

Point::Point( ) : _x(0), _y(0) { return ; }
Point::Point( int const x, int const y ) : _x(x), _y(y) { return ; }
Point::Point( Fixed const x, Fixed const y ) : _x(x), _y(y) { return ; }
Point::Point( Point const & src ) : _x(src._x), _y(src._y) { return ; }

Point::~Point( ) { return ; }

Point	Point::operator=( Point const & rhs ) {
	(void) rhs;

	return *this;
}

Point	Point::operator-( Point const & rhs ) { 
	
	return Point( _x - rhs.getX(), _y - rhs.getY() );
}

Fixed	Point::getX( ) const { return this->_x; }
Fixed	Point::getY( ) const { return this->_y; }

std::ostream &	operator<<( std::ostream & o, Point const & rhs ) {

	o << "( " <<  rhs.getX() << ", " << rhs.getY()<< " )";
	return o;
}
