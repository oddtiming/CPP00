#include <stdio.h>

int	main( )
{

	// type qualifiers == const, olatiles

	int			a = 42;				// Reference value

	int const *	b = &a;					// Implicit type qualifier const
	int const *	c = (int const *) &a;	// Explicit type qualifier const

	int const *	d = &a;				// Implicit promotion	--> OK
	int *		f = (int *) d;		// Explicit demotion	--> OK, b/c explicit

	// This line will not compile
	int *		e = d;				// Implicit demotion	--> Nooooope
	
	
	return 0;
}
