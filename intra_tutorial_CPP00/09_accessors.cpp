#include <iostream>
#include "09_Sample.hpp"

int	main( void ) {
	Sample	instance;

	std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;

	instance.setFoo( 42 );
	std::cout << "after setFoo( 42 ), instance.getFoo(): " << instance.getFoo() << std::endl;

	instance.setFoo( -2 );
	std::cout << "after setFoo( -2 ), instance.getFoo(): " << instance.getFoo() << std::endl;

	return 0;
}
