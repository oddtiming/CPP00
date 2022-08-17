#include <iostream>
#include "10_Sample.hpp"

Sample::Sample( int foo ) : _foo(foo) {
	
	std::cout << "Const constructor called" << "\n";
	return ;
}

Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Sample::getFoo( void ) const {

	return this->_foo;
}

int	Sample::compare( Sample * other ) const {

	if (other->getFoo() == this->_foo) {
		return 0;
	}

	return ( this->_foo > other->getFoo() ) ? 1 : -1;
}
