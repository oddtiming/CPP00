#include <iostream>
#include "03_Sample.hpp"

int	main(void) {

	Sample instance;

	instance.foo = 42;
	std::cout << "instance.foo = " << instance.foo << std::endl;

	instance.bar();

	return 0;
}
