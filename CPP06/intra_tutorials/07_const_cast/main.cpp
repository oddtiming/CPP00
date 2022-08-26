#include <iostream>

// const_cast allows us to cast const values into non-const...

// not sure I get why you'd use that ?

// usually a sign that your code is wrong


int	main( ) {

	int		a = 42;				// Reference value

	int const *	b = &a;						// Implicit promotion	-> OK
	// int *		c = b;						// Explicit promotion	-> NO! Will not compile
	int	*		d = const_cast<int *>(b);	// Explicit promotion	-> OK, as you wish

	*d = 2;

	std::cout << a << std::endl;
	
	return 0;
}
