#include <iostream>
#include "04_Sample.hpp"

int	main(void) {

	Sample instance;

	std::cout << "instance.foo after init: " << instance.foo << std::endl;
	instance.foo = 41;
	std::cout << "instance.foo after changing it: " << instance.foo << std::endl;

	instance.bar();

	return 0;
}
