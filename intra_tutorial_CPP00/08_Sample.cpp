#include <iostream>
#include "08_Sample.hpp"

Sample1::Sample1( void ) {
	
	std::cout << "Const constructor called" << "\n";
	return ;
}

Sample1::~Sample1( void ) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Sample1::bar( void ) const {

	std::cout << "Member fct this->bar() has been called" << std::endl;
	return ;
}

Sample2::Sample2( void ) {
	
	std::cout << "Const constructor called" << "\n";
	return ;
}

Sample2::~Sample2( void ) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Sample2::bar( void ) const {

	std::cout << "Member fct this->bar() has been called" << std::endl;
	return ;
}
