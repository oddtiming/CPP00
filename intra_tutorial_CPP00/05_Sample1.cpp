#include <iostream>
#include "05_Sample1.hpp"

Sample1::Sample1( void ) {
	
	std::cout << "Default constructor called" << std::endl;

	// Default constructor initialized
	this->a1 = '\0';
	this->a2 = 0;
	this->a3 = 0.0F;

	std::cout << "All member attributes are null-initialized" << std::endl;

	return ;
}

// The most intuitive way to use a constructor, but slightly
Sample1::Sample1( char p1, int p2, float p3 ) {
	
	std::cout << "Parametered constructor called" << "\n";

	this->a1 = p1;
	std::cout << "this->a1: " << this->a1 << "\n";

	this->a2 = p2;
	std::cout << "this->a2: " << this->a2 << "\n";

	this->a3 = p3;
	std::cout << "this->a3: " << this->a3 << std::endl;

	return ;
}

Sample1::~Sample1( void ) {

	std::cout << "Destructor called" << std::endl;
	return ;
}
