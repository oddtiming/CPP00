#include <iostream>
#include <iomanip>


// This defines a default type
template< typename T = float >
class Vertex {

public:
	Vertex<T>( T const & x, T const & y, T const &z ) : _x(x), _y(y), _z(z) { }
	~Vertex<T>(  ) { }

	T const &	getX( )  const { return this->_x; }
	T const &	getY( )  const { return this->_y; }
	T const &	getZ( )  const { return this->_z; }
	T const &	max( )  const { return ( _z > _y ? _z : (_y > _x ? _y : _x) ); }

	//...

private:
	T const		_x;
	T const		_y;
	T const		_z;

	// Block construction without 3 parameters
	Vertex<T>(  ) { }
};

template< typename T >
std::ostream &	operator<<( std::ostream & o, Vertex<T> const &p) {
	o	<< std::boolalpha 
		<< std::setiosflags( std::ios::fixed )
		<< std::setprecision( 2 )
		<< "Vertex( " 
		<< p.getX() << ", " 
		<< p.getY() << ", "
		<< p.getZ() << " )";
	return o;
}

