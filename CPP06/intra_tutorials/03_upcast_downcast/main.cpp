#include <iostream>

class Parent				{};
class Child1: public Parent	{};
class Child2: public Parent	{};

int	main( ) {

	Child1	a;					// ref value

	Parent	*b = &a;			// Implicit "reinterpretation" cast
	Parent	*c = (Parent *) &a;	// Explicit "reinterpretation" cast

	Parent	*d = &a;			// Implicit upcast		-> OK
	// Child1	*e = d;				// Implicit downcast	-> Nooope! Will not compile
	Child2	*f = (Child2 *) d;	// Explicit downcast	-> OK, but weird since wrong

	return 0;
}
