#include <iostream>
#include "Bureaucrat.hpp"

int main( ) {

	Bureaucrat billyBob( "billyBob", 1 );
	Bureaucrat unnamed;

	std::cout << unnamed << std::endl;

	std::cout << billyBob << " does indeed exist!";

	try {
		unnamed.promote();
		unnamed.demote();
		unnamed.demote();

 	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
 	}


	try {
		billyBob.demote();
		billyBob.promote();
		billyBob.promote();

 	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
 	}

	return 0;
}
