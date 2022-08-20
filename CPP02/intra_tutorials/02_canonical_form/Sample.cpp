#include "Sample.hpp"

Sample::Sample( void ) : _n(0) {
	std::cout << __FUNCTION__ << " called" << std::endl;
	return ;
}

Sample::Sample( int const n ) : _n(n) {
	std::cout << __FUNCTION__ << " parametric constructor called" << std::endl;
}

Sample::Sample( Sample const & src ) {
	std::cout << __FUNCTION__ << " copy constructor called" << std::endl;

	*this = src;
}

Sample &	Sample::operator=( Sample const & rhs ) {
	std::cout << __FUNCTION__ << " assignment operator called" << std::endl;

	this->_n = rhs.getValue();
}

Sample::~Sample( void ) {
	std::cout << __FUNCTION__ << " called" << std::endl;
}

int			Sample::getValue( void ) const {
	return this->_n;
}

//	Indirection operator overload to extract the value
std::ostream &	operator<<( std::ostream & o, Sample const & rhs ) {

	o << rhs.getValue();
	return o;
}
