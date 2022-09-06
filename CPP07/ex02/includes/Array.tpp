
#pragma once

#include "Array.hpp"
#include <iostream>
#include <iomanip>

template< typename T >
class Array {

public:

	/* Constructors/destructors */
	Array<T>( ) : _n(1), _data(new T()) {
			std::cout << "Generic template<T> called w " << _data << std::endl;
	}

	Array<T>( uint n ) 
		: _n(n), _data( new T[n] ) {
			std::cout << "Generic template<T> called w " << _n << std::endl;
	}

	Array<T>( uint n, T & val ) 
		: _n(n) {
			std::cout << "Generic template<T> called w " << _n << " and val: " << val << std::endl;

			_data = new T[n];
			for (uint i = 0; i < _n ; i++) {
				_data[i] = val;
			}
	}

	Array<T>( Array & rhs ) : _n(rhs._n) {
			std::cout << "template<T> copy constructor called" << std::endl;
			this->_data = new T[_n];
			for (uint i = 0; i < _n ; i++) {
				_data[i] = rhs.getAt(i);
			}
	}

	~Array<T>( ) { 
		std::cout << "~Array called" << std::endl;
		delete [] _data;
	}


	/* Copy assignment operator */
	Array const & operator=( Array const & rhs ) {
		this->~Array();
		std::cout << "template<T> copy assignment operator called" << std::endl;
		this->_data = new T[_n];
		for (uint i = 0; i < _n ; i++) {
			_data[i] = rhs.getAt(i);
		}
		return *this;
	}


	/* Getters/Setters */

	T const *		getData( ) const { return this->_data; }
	T *				getData( ) { return this->_data; }
	uint const &	getN(  ) const { return this->_n; }
	T const &		getAt( size_t n ) const { 
		if (n >= this->_n) {
			throw ArrayIndexOutOfBoundsException( n, this->_n );
		}
		return this->_data[n];
	}


	/* Operator overloads */
	T const &operator[]( size_t n )			const	{ return this->getAt(n); }
	T const &operator*( Array const & lhs )	const	{ return lhs.getData; }

private:
	uint	_n;
	T *		_data;

};


template< typename T >
std::ostream &	operator<<( std::ostream & o, Array<T> const &p) {
	o	<< std::boolalpha 
		<< std::setiosflags( std::ios::fixed )
		<< std::setprecision( 2 );
	uint n = p.getN();
	for ( uint i = 0; i < n; i++ ) {

		o	<< "p[" << i << "]: "
			<< p[i] << std::endl;
	}
	return o;
}
