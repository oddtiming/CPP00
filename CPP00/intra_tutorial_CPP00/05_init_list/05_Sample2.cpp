#include <iostream>
#include "05_Sample2.hpp"

// init_list style initialization
// It is a preferred syntax 
Sample2::Sample2( char p1, int p2, float p3 ) : a1(p1), a2(p2), a3(p3) {
	
	std::cout << "Parametered constructor called" << "\n";

	std::cout << "this->a1: " << this->a1 << "\n";
	std::cout << "this->a2: " << this->a2 << "\n";
	std::cout << "this->a3: " << this->a3 << std::endl;

	return ;
}

Sample2::~Sample2( void ) {

	std::cout << "Destructor called" << std::endl;
	return ;
}
