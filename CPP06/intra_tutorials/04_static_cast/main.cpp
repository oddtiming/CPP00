#include <iostream>

// static_cast is probably the most common conversion
// allows us to navigate heritage tree

class Parent				{};

class Child1: public Parent	{};
class Child2: public Parent	{};

class Other					{};

int	main( ) {

	int		a = 42;						// Reference value

	double	b = a;						// Implicit promotion	-> OK
	int		c = b;						// Implicit promotion	-> Not advised
	int		d = static_cast<int>(b);	// Explicit promotion	-> OK

	// This asks a static cast on `b' towards an int


	Child1	e;								// ref value

	Parent	*f = &e;						// Implicit upcast		-> OK
	// Child1	*h = f;							// Implicit downcast	-> Nooope! Will not compile
	Child2	*i = static_cast<Child2 *>(f);	// Explicit downcast	-> OK, but weird since wrong


	// Other	*j = static_cast<Other *>(f);	// Explicit conversion		-> No ! No known conversion
	Other	*k = (Other *)(f);				// Explicit c conversion	-> This will work. Yikes


	return 0;
}
