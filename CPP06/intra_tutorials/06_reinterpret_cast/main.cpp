#include <iostream>

// reinterpret_cast can reinterpret, but also upcast and downcast
// most permissive of cpp casts

// Only used in cases where you lose the type along the way

int	main( ) {

	float		a1 = 42.42f;						// Reference value

	void *		b1 = &a1;							// Implicit promotion	-> OK
	int *		c1 = reinterpret_cast<int *>(b1);	// Explicit promotion	-> OK, as you wish
	int	&		d1 = reinterpret_cast<int &>(b1);	// Explicit promotion	-> OK, as you wish
	
	return 0;
}
