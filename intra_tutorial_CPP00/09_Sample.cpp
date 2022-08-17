#include <iostream>
#include "09_Sample.hpp"

Sample::Sample( void ) {
	
	std::cout << "Const constructor called" << "\n";
	this->_foo = 0;
	return ;
}

Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Sample::getFoo( void ) const {

	return this->_foo;
}

void	Sample::setFoo( int newFoo ) {

	if (newFoo >= 0) {
		this->_foo = newFoo;
	}

	return ;
}
