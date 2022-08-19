#include <iostream>
#include "04_Sample.hpp"

Sample::Sample( void ) {
	
	std::cout << "Constructor called" << std::endl;

	// Dereferencing is necessary b/c "this" is a pointer
	this->foo = 42;
	std::cout << "In constructor, this->foo = " << this->foo << std::endl;

	this->bar();

	return ;
}

Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Sample::bar( void ) {

	std::cout << "Member function bar() called" << std::endl;
	return ;
}
