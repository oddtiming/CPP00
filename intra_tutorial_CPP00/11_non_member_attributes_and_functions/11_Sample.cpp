#include <iostream>
#include "11_Sample.hpp"

Sample::Sample( void ) {
	
	std::cout << "Const constructor called" << "\n";

	this->_nbInstances++;

	return ;
}

Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	
	this->_nbInstances--;
	
	return ;
}


// Note that as a static member function, the implicit `this' does not get passed
int	Sample::getNbInstances( void ) {

	// this->_nbInstances will return an error here, as a non-instance member function 

	return Sample::_nbInstances;
}

int	Sample::_nbInstances = 0;

/**
 * @brief Line 31 is incredibly important here, since otherwise, 
 * 		it will not be known by member functions.
 * 
 * 		It makes sense, since its value is independent of anuy instances, 
 * 		therefore it needs to be initiated independently
 * 
 */
