
#pragma once

#include "Array.hpp"
#include <iostream>
#include <iomanip>

template< typename T >
class Array {

public:

/* Constructors */
	Array( )
		: _n(0), _data(new T[0]) {
			std::cout << "Array<T> default constructor called" << std::endl;
	}

	Array( size_t n ) 
		: _n(n), _data( new T[_n] ) {
			std::cout << "Array<T> parametric constructor called w size: " << _n << std::endl;
	}

	Array( size_t n, T & val ) 
		: _n(n), _data( new T[_n] ) {
			std::cout << "Array<T> parametric constructor called w size: " << _n << " and val: " << val << std::endl;

			for (size_t i = 0; i < _n ; i++) {
				_data[i] = val;
			}
	}

	Array( Array & rhs ) 
		: _n(rhs._n), _data( new T[_n] ) {
			std::cout << "Array<T> copy constructor called" << std::endl;
			for (size_t i = 0; i < _n ; i++) {
				_data[i] = rhs.getAt(i);
			}
	}

/* Destructor */
	~Array( ) { 
		std::cout << "~Array called" << std::endl;
		delete [] this->_data;
	}


/* Copy assignment operator */
	Array const & operator=( Array const & rhs ) {
		std::cout << "Array<T> copy assignment operator called" << std::endl;

		delete [] this->_data;
		
		this->_n = rhs._n;
		this->_data = new T[_n];

		for (size_t i = 0; i < _n ; i++) {
			_data[i] = rhs.getAt(i);
		}
		return *this;
	}


/* Getters/Setters */
	T const *		getData( ) const { return this->_data; }
	T *				getData( ) { return this->_data; }
	size_t const &	getN(  ) const { return this->_n; }
	
	T &		getAt( size_t n ) { 
		if (n >= this->_n) {
			throw ArrayIndexOutOfBoundsException( n, this->_n );
		}
		return this->_data[n];
	}
	T const &		getAt( size_t n ) const { 
		if (n >= this->_n) {
			throw ArrayIndexOutOfBoundsException( n, this->_n );
		}
		return this->_data[n];
	}

/* Member functions */
	size_t const & size( ) const { return this->_n; }

/* Operator overloads */
	T & operator[]( size_t n )				{ return this->getAt(n); }
	T const & operator[]( size_t n ) const	{ return this->getAt(n); }

private:
	size_t	_n;
	T *		_data;

};


template< typename T >
std::ostream &	operator<<( std::ostream & o, Array<T> const &p) {
	// Set iomanip flags
	o	<< std::boolalpha 
		<< std::setiosflags( std::ios::fixed )
		<< std::setprecision( 2 );
	
	// Print Array values
	size_t n = p.getN();
	for ( size_t i = 0; i < n; i++ ) {

		o	<< "p[" << i << "]: "
			<< p[i] << std::endl;
	}
	return o;
}
