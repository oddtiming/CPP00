#include <stdio.h>


int		max_int		( int a, int b ) { return (a >= b ? a : b); }
float	max_float	( float a, float b ) { return (a >= b ? a : b); }
char	max_char	( char a, char b ) { return (a >= b ? a : b); }

int		foo( int x ) { printf("Long computing time... %d \n", x); return x; }

#define max( x, y ) ( ((x) >= (y)) ? (x) : (y) )

int	main( ) {

	int a = 21;
	int b = 42;

	printf("Max of %d and %d is %d\n", a, b, max_int(a, b));
	printf("Max of %d and %d is %d\n", a, b, max(a, b));

	float c = 21.0f;
	float d = 42.0f;

	printf("Max of %2ff and %2ff is %2ff\n", c, d, max_float(c, d));
	printf("Max of %2ff and %2ff is %2ff\n", c, d, max(c, d));

	char e = 42;
	char f = 93;

	printf("Max of %c and %c is %c\n", e, f, max_char(e, f));
	printf("Max of %c and %c is %c\n", e, f, max(e, f));

	// but...
	printf("Max of %d and %d is %d\n", a, b, max_int(foo(a), foo(b)));
	printf("Max of %d and %d is %d\n", a, b, max(foo(a), foo(b)));

	return 0;
}
