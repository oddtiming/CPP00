
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

Fixed	Fixed::operator+( Fixed const & rhs ) const {

	std::cout << "Arithmetic Addition operator called" << std::endl;
	Fixed result;
	result.setRawBits( this->_integer + rhs.getRawBits() );
	return result;
}

Fixed	Fixed::operator-( Fixed const & rhs ) const {

	std::cout << "Arithmetic Substraction operator called" << std::endl;
	Fixed result;
	result.setRawBits( this->_integer - rhs.getRawBits() );
	return result;
}


// Fixed Point Arithmetic ressource : 
// https://github.com/eteran/cpp-utilities/blob/master/fixed/include/cpp-utilities/fixed.h
Fixed	Fixed::operator*( Fixed const & rhs ) const {

	std::cout << "Arithmetic Multiplication operator called" << std::endl;

	Fixed result;
	result.setRawBits((this->_integer * rhs.getRawBits()) >> _nbFractionalPoints);
	return result;
}

Fixed	Fixed::operator/( Fixed const & rhs ) const {

	std::cout << "Arithmetic Division operator called" << std::endl;

	Fixed result;
	result.setRawBits( (this->_integer << _nbFractionalPoints) / rhs.getRawBits() );
	return result;
}


Fixed	Fixed::operator>( Fixed const & rhs ) const {

	std::cout << "Relational Greater Than operator called" << std::endl;
	return Fixed( this->_integer > rhs.getRawBits() );
}

Fixed	Fixed::operator<( Fixed const & rhs ) const {

	std::cout << "Relational Smaller Than operator called" << std::endl;
	return Fixed( this->_integer < rhs.getRawBits() );
}

Fixed	Fixed::operator==( Fixed const & rhs ) const {

	std::cout << "Relational Equal To operator called" << std::endl;
	return Fixed( this->_integer == rhs.getRawBits() );
}

Fixed	Fixed::operator!=( Fixed const & rhs ) const {

	std::cout << "Relational Not Equal To operator called" << std::endl;
	return Fixed( this->_integer != rhs.getRawBits() );
}

Fixed	Fixed::operator>=( Fixed const & rhs ) const {

	std::cout << "Relational Greater Than or Equal To operator called" << std::endl;
	return Fixed( this->_integer >= rhs.getRawBits() );
}

Fixed	Fixed::operator<=( Fixed const & rhs ) const {

	std::cout << "Relational Smaller Than or Equal To operator called" << std::endl;
	return Fixed( this->_integer <= rhs.getRawBits() );
}

Fixed	Fixed::operator++( void ) {

	std::cout << "Prefix increment operator called" << std::endl;
	this->_integer++;
	return *this;
}

Fixed 	Fixed::operator++( int ) {

	std::cout << "Postfix increment operator called" << std::endl;
	Fixed	prevFixed( *this );
	++*this;
	return prevFixed;
}

Fixed	Fixed::operator--( void ) {

	std::cout << "Prefix decrement operator called" << std::endl;
	this->_integer--;
	return *this;
}

Fixed 	Fixed::operator--( int ) {

	std::cout << "Postfix decrement operator called" << std::endl;
	Fixed	prevFixed( *this );
	--*this;
	return prevFixed;
}

// Fixed	Fixed::operator ++ ()//												operator (int)++
// {
// 	this->_integer++;
// 	return (*this);
// }

// Fixed	Fixed::operator ++ (int)//								operator ++(int)
// {
// 	Fixed	res(*this);
// 	operator ++ ();
// 	return (res);
// }

// Fixed	Fixed::operator -- ()//									operator (int)--
// {
// 	this->_integer--;
// 	return (*this);
// }

// Fixed	Fixed::operator -- (int)//								operator --(int)
// {
// 	Fixed	res(*this);
// 	operator -- ();
// 	return (res);
// }


// const Fixed &	Fixed::operator++( void ) {

// 	std::cout << "Prefix increment operator called for const member" << std::endl;
// 	this->_integer--;
// 	return *this;
// }

// const Fixed 	Fixed::operator++( int ) const {

// 	std::cout << "Postfix increment operator called for const member" << std::endl;
// 	Fixed	prevFixed( *this );
// 	++*this;
// 	return prevFixed;
// }

// const Fixed &	Fixed::operator--( void ) {

// 	std::cout << "Prefix decrement operator called for const member" << std::endl;
// 	this->_integer--;
// 	return *this;
// }

// const Fixed 	Fixed::operator--( int ) const {

// 	std::cout << "Postfix decrement operator called for const member" << std::endl;
// 	Fixed	prevFixed( *this );
// 	--*this;
// 	return prevFixed;
// }

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Fixed::setRawBits( int const integer ) {

	std::cout << __FUNCTION__ << " member function called" << std::endl;
	this->_integer = integer;
	return ;
}

int		Fixed::getRawBits( void ) const {

	std::cout << __FUNCTION__ << " member function called" << std::endl;
	return this->_integer;
}

float	Fixed::toFloat( void ) const {

	std::cout << __FUNCTION__ << " member function called" << std::endl;
	return ( (float)_integer / (float)(1 << _nbFractionalPoints) );
}

int		Fixed::toInt( void ) const {

	std::cout << __FUNCTION__ << " member function called" << std::endl;
	return ( _integer >> _nbFractionalPoints );
}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {

	o << rhs.toFloat();
	return o;
}
