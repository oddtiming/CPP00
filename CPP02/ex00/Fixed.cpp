#include "Fixed.hpp"

Fixed::Fixed( void ) : _integer(0) {
	std::cout << "Constructor called" << std::endl;
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

	this->_integer = integer;

	std::cout << __FUNCTION__ << " member function called" << std::endl;
}

int		Fixed::getRawBits( void ) const {
	std::cout << __FUNCTION__ << " member function called" << std::endl;
	return this->_integer;
}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {

	o << rhs.getRawBits();
	return o;
}
