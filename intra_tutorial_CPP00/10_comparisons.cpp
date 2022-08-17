#include <iostream>
#include "10_Sample.hpp"

int	main( void ) {
	Sample instance1( 42 );
	Sample instance2( 42 );

	if ( &instance1 == &instance2 )
		std::cout << "Instance 1 and 2 are physically equal :D\n";
	else 
		std::cout << "Instance 1 and 2 are not physically equal :(\n";

	if ( instance1.compare(&instance2) == 0 )
		std::cout << "Instance 1 and 2 are structurally equal :D\n";
	else if ( instance1.compare(&instance2) > 0 )
		std::cout << "Instance 1 > instance 2\n";
	else
		std::cout << "Instance 1 > instance 2\n";



	std::cout << "instance1.getFoo(): " << instance1.getFoo() << std::endl;
	std::cout << "instance2.getFoo(): " << instance2.getFoo() << std::endl;

	std::cout << "instance1.compare(&instance1): " << instance1.compare(&instance1) << std::endl;
	std::cout << "instance1.compare(&instance2): " << instance1.compare(&instance2) << std::endl;

	return 0;
}
