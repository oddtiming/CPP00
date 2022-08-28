
#pragma once

#include "Array.hpp"
#include <iostream>
#include <iomanip>

template< typename T >
class Array {

public:
	Array<T>( uint n ) 
		: _n(n), _data( new T[n] ) {
			std::cout << "Generic template<T> called w " << _n << std::endl;
	}

	Array<T>( uint n, T & val ) 
		: _n(n), _data( new T[n] ) {
			std::cout << "Generic template<T> called w " << _n << " and val: " << val << std::endl;
			for (uint i = 0; i < _n; i++) {

				/**
				 * todo: DEBUG
				 * 
				 */
				
				*(&_data + (i * sizeof(*_data) ) ) = new T( val );
			}
	}

	Array<T>( Array & rhs ) {
			this->~Array();
			// *this = rhs;
			this->_n = rhs._n;
			this->_data = new T(_n);
			for (uint i = 0; i < this->_n; i++)
				_data[i] = rhs[i];
	}

	// Copy assignment operator
	Array const & operator=( Array const & rhs ) {
		this->~Array();
		this->_n = rhs._n;
		this->_data = new T(_n);
		for (uint i = 0; i < this->_n; i++)
			_data[i] = rhs[i];
		return *this;
	}


	~Array<T>( ) { 
		std::cout << "~Array called" << std::endl;
		delete [] _data;
	}
	Array<T>( ) : _n(0), _data(nullptr) {
			std::cout << "Generic template<T> called w " << _data << std::endl;
	}

	T const *		getData( ) const { return this->_data; }
	T *				getDataNonConst( ) const { return this->_data; }
	uint const &	getN(  ) const { return this->_n; }
	T const &		getAt( size_t n ) const { 
		if (n >= this->_n) {
			throw ArrayIndexOutOfBoundsException();
		}
		return this->_data[n];
	}


	T const &operator[]( size_t n ) const { 
		return this->getAt(n); }
	T const &operator*( Array const & lhs ) const { 
		return lhs.getData; }

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
