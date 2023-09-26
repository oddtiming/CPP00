#include <iostream>
#include <iomanip>


// This defines a default type
template< typename T = float >
class Vertex {

public:
	Vertex<T>(  ) : _x(0), _y(0), _z(0) { }
	Vertex<T>( T const & x, T const & y, T const &z ) : _x(x), _y(y), _z(z) { }
	Vertex<T>( Vertex const & rhs ) : _x(rhs.x), _y(rhs.y), _z(rhs.z) { }

	~Vertex<T>(  ) { }

	Vertex const &operator=( Vertex const & rhs ) {
		this->_x = rhs._x;
		this->_y = rhs._y;
		this->_z = rhs._z;
		return *this;
	}
	

	T const &	getX( )  const { return this->_x; }
	T const &	getY( )  const { return this->_y; }
	T const &	getZ( )  const { return this->_z; }
	void		setX( T const & x ) { this->_x = x; }
	void		setY( T const & y ) { this->_y = y; }
	void		setZ( T const & z ) { this->_z = z; }
	T const &	max( )  const { return ( _z > _y ?  (_y > _x ? _y : _x) : _z ); }

	//...

private:
	T		_x;
	T		_y;
	T		_z;

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

