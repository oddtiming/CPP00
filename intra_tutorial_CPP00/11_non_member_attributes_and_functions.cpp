#include <iostream>
#include "11_Sample.hpp"

void	foo( void ) {
	Sample instance;


	std::cout << "in foo(): " << Sample::getNbInstances() << std::endl;
}

int	main( void ) {
	std::cout << Sample::getNbInstances() << std::endl;

	Sample inst1;
	Sample inst2;
	std::cout << Sample::getNbInstances() << std::endl;

	foo();

	Sample inst3;
	foo();
	Sample inst4;
	std::cout << Sample::getNbInstances() << std::endl;

	return 0;
}
