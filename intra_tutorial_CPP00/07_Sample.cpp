#include <iostream>
#include "07_Sample.hpp"

Sample::Sample( void ) : publicFoo( 42 ), _privateFoo( -42 ) {
	
	std::cout << "Const constructor called" << "\n";

	this->publicBar();

	return ;
}

Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Sample::publicBar( void ) const {

	std::cout << "Public member fct this->publicBar() has been called" << std::endl;
	std::cout << "this->publicFoo = " << this->publicFoo << std::endl;
	std::cout << "this->_privateFoo = " << this->_privateFoo << std::endl;
	return ;
}

void	Sample::_privateBar( void ) const {

	std::cout << "Private member fct this->_privateBar() has been called" << std::endl;
	return ;
}
