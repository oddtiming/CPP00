#include <iostream>
#include "12_Sample.hpp"

Sample::Sample( void ) : foo( 0 ) {
	
	std::cout << "Const constructor called" << "\n";
	return ;
}

Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Sample::bar( void ) const{

	std::cout << "Sample::bar() member fct called" << std::endl;

	return ;
}
