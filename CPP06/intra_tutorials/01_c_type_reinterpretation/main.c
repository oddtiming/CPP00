#include <stdio.h>

int	main( )
{

	float	a = 420.042f;		// Reference value

	void *	b = &a;				// Implicit reinterpretation cast
	void *	c = (void *) &a;	// Explicit reinterpretation cast

	void *	d = &a;				// Implicit promotion	--> OK
	int *	e = d;				// Implicit demotion	--> Hazardous, loses precision
	int *	f = (int *) d;		// Explicit demotion	--> OK, b/c explicit

	// float* and int* will give different results
	// coming from the same void*

	//	float
	printf("%p, %f\n", &a, a);
	
	//	void *
	printf("%p\n", b);
	printf("%p\n", c);
	printf("%p\n", d);
	
	//	int *
	printf("%p, %d\n", e, *e);
	printf("%p, %d\n", f, *f);

	return 0;
}
