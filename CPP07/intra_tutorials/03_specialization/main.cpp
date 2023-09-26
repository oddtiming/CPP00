#include <iostream>

template< typename T, typename U >
class Pair {

public:
	Pair<T, U>( T const & lhs, U const & rhs ) 
		: _lhs(lhs), _rhs(rhs) {
			std::cout << "Generic template<T,U> called w " << _lhs << std::endl;
		}

	~Pair<T, U>(  ) { std::cout << "~Pair called" << std::endl; }

	T const & first( ) const { return this->_lhs; }
	U const & second( ) const { return this->_rhs; }

private:
	T const &	_lhs;
	U const &	_rhs;

	Pair<T, U>(void);	//To prevent empty instantiation
};



// Partial specialization
template<typename U >
class Pair<int, U> {	// Here the types are specified

public:
	Pair<int, U>( int lhs, U const & rhs ) 
		: _lhs(lhs), _rhs(rhs) {
			std::cout << "Partially specialized template<int, U> called w " << _lhs << std::endl;
		}

	~Pair<int, U>(  ) { std::cout << "~Pair called" << std::endl; }

	int			first( ) const { return this->_lhs; }
	U const &	second( ) const { return this->_rhs; }

private:
	int			_lhs;
	U const &	_rhs;

	Pair<int, U>(void);	//To prevent empty instantiation
};


// Complete specialization
template<>
class Pair<bool, bool> {	// Here the types are specified

public:
	Pair<bool, bool>( bool lhs, bool rhs ) {
			std::cout << "Fully specialized template<bool, bool> called" << std::endl;
			this->_n = static_cast<int>(lhs) << 0;
			this->_n |= static_cast<int>(rhs) << 1;
		}

	~Pair<bool, bool>(  ) { std::cout << "~Pair called" << std::endl; }

	bool	first( ) const	{ return this->_n & 0x1; }
	bool	second( ) const	{ return this->_n & 0x2; }

private:
	int	_n;

	Pair<bool, bool>(void);	//To prevent empty instantiation
};

template< typename T, typename U >
std::ostream &	operator<<( std::ostream & o, Pair<T,U> const &p) {
	o << "Pair(" << p.first() << ", "  << p.second() << ")";
	return o;
}

std::ostream &	operator<<( std::ostream & o, Pair<bool, bool> const &p) {
	o << std::boolalpha << "Pair(" << p.first() << ", "  << p.second() << ")";
	return o;
}


int	main( ) {

	Pair< int, float >			a( 42, 4.2f );
	Pair< void *, double >		b( &a, 9e300 );
	Pair< Pair< int, float >, Pair<char, bool> >	c( a, Pair< char, bool >('c', true) );
	Pair< bool, bool >	d( false, true );


	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;


	return 0;

}