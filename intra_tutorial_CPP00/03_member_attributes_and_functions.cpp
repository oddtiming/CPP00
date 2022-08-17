#include <iostream>
#include "03_Sample.hpp"

// Class accessors have same syntax as namespaces
Sample::Sample( void ) {
	
	std::cout << "Constructor called" << std::endl;

	// Destructors and Constructors have no return value by default
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
