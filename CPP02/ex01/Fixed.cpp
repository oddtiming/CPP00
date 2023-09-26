
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed( void ) : _integer(0) {
	std::cout << "Constructor called" << std::endl;
	return ;
}

Fixed::Fixed( float const f ) : _integer( (int)( roundf(f * (1 << _nbFractionalPoints)) ) ) {

	// std::cout << "_integer " << _integer << std::endl;
	// std::cout << "_integer >> _nbFractionalPoints) " << (_integer >> _nbFractionalPoints) << std::endl;
	// std::cout <<  (int8_t)((f * (1 << _nbFractionalPoints)) ) << std::endl;
	// this->_integer = (_integer >> _nbFractionalPoints);
	// this->_integer <<= _nbFractionalPoints;
	// // while ( _integer )
	// // this->integer += ;
	// std::cout << f << std::endl;
	std::cout << "Int constructor called" << std::endl;
	return ;

}

Fixed::Fixed( int const n ) : _integer( n << _nbFractionalPoints ) {
	std::cout << "Int constructor called" << std::endl;
	return ;

}

Fixed::Fixed( Fixed const & src ) {
	std::cout << "Copy constructor called" << std::endl;

	*this = src;
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {
	std::cout << "Assignment operator called" << std::endl;

	this->_integer = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits( int const integer ) {

	std::cout << __FUNCTION__ << " member function called" << std::endl;

	this->_integer = integer;
}

int		Fixed::getRawBits( void ) const {
	std::cout << __FUNCTION__ << " member function called" << std::endl;
	return this->_integer;
}

float	Fixed::toFloat( void ) const {
	 return ( (float)_integer / (float)(1 << _nbFractionalPoints) );
}

int		Fixed::toInt( void ) const {
	return ( _integer >> _nbFractionalPoints );
}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {

	o << rhs.toFloat();
	return o;
}
