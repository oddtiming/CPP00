#include <cmath>
#include "Fixed.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

Fixed::Fixed( ) : _n(0) { return ; }
Fixed::Fixed( float const f ) : _n( (int)( roundf(f * (1 << _nbFract)) ) ) { return ; }
Fixed::Fixed( int const n ) : _n( n << _nbFract ) { return ; }
Fixed::Fixed( Fixed const & src ) {	*this = src; }
Fixed::~Fixed( ) { return ; }

/*****************************************************************************/
/*                          Assignment operators                             */
/*****************************************************************************/

Fixed &	Fixed::operator=( Fixed const & rhs ) {

	this->_n = rhs.getRawBits();
	return *this;
}

/*****************************************************************************/
/*                          Arithmetic operators                             */
/*****************************************************************************/
// Fixed Point Arithmetic ressource : 
// https://spin.atomicobject.com/2012/03/15/simple-fixed-point-math/
// https://github.com/eteran/cpp-utilities/blob/master/fixed/include/cpp-utilities/fixed.h

Fixed	Fixed::operator+( Fixed const & rhs ) const {

	Fixed result;
	result.setRawBits( this->_n + rhs.getRawBits() );
	return result;
}

Fixed	Fixed::operator-( Fixed const & rhs ) const {

	Fixed result;
	result.setRawBits( this->_n - rhs.getRawBits() );
	return result;
}

Fixed	Fixed::operator*( Fixed const & rhs ) const {

	Fixed result;
	result.setRawBits((this->_n * rhs.getRawBits()) >> _nbFract);
	return result;
}

Fixed	Fixed::operator/( Fixed const & rhs ) const {

	Fixed result;
	result.setRawBits( (this->_n << _nbFract) / rhs.getRawBits() );
	return result;
}

/*****************************************************************************/
/*                          Relational operators                             */
/*****************************************************************************/

bool	Fixed::operator >  ( Fixed const & rhs ) const { return ( this->_n > rhs.getRawBits() ); }
bool	Fixed::operator <  ( Fixed const & rhs ) const { return ( this->_n < rhs.getRawBits() ); }
bool	Fixed::operator == ( Fixed const & rhs ) const { return ( this->_n == rhs.getRawBits() ); }
bool	Fixed::operator != ( Fixed const & rhs ) const { return ( this->_n != rhs.getRawBits() ); }
bool	Fixed::operator >= ( Fixed const & rhs ) const { return ( this->_n >= rhs.getRawBits() ); }
bool	Fixed::operator <= ( Fixed const & rhs ) const { return ( this->_n <= rhs.getRawBits() ); }

/*****************************************************************************/
/*                       Incrementers / Decrementers                         */
/*****************************************************************************/
Fixed &	Fixed::operator++( ) {			// Prefix increment operator (i++)

	this->_n++;
	return *this;
}

Fixed 	Fixed::operator++( int ) {		// Postfix increment operator (++i)

	Fixed	prevFixed( *this );
	++*this;
	return prevFixed;
}

Fixed &	Fixed::operator--( ) {			// Prefix decrement operator (i--)

	this->_n--;
	return *this;
}

Fixed 	Fixed::operator--( int ) {		// Postfix decrement operator (--i)

	Fixed	prevFixed( *this );
	--*this;
	return prevFixed;
}

/*****************************************************************************/
/*                             Getters/Setters                               */
/*****************************************************************************/

void	Fixed::setRawBits( int const integer ) { this->_n = integer; }
int		Fixed::getRawBits( ) const { return this->_n; }
float	Fixed::toFloat( ) const { return ( (float)_n / (float)(1 << _nbFract) ); }
int		Fixed::toInt( ) const { return ( _n >> _nbFract ); }

/*****************************************************************************/
/*                             Class functions                               */
/*****************************************************************************/

Fixed &			Fixed::min( Fixed & a, Fixed & b ) {
	return (a.getRawBits() > b.getRawBits() ? b : a);
}

Fixed const &	Fixed::min( Fixed const & a, Fixed const & b ) {
	return (a.getRawBits() > b.getRawBits() ? b : a);
}

Fixed &			Fixed::max( Fixed & a, Fixed & b ) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

Fixed const &	Fixed::max( Fixed const & a, Fixed const & b ) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}


std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {
	
	o << rhs.toFloat();
	return o;
}
