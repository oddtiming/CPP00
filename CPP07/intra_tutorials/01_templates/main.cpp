#include <iostream>

int	max_old( int x, int y ) {
	return (x > y ? x : y );
}

int		foo( int x ) { printf("Long computing time... %d \n", x); return x; }

// This is a precompiler direction. 
// typename is another keyword. Could be class, or function
template< typename T >
T const &	max( T const & x, T const & y ) {
	return (x > y ? x : y );
}

int	main( ) {

	int a = 21;
	int b = 42;

	std::cout << "Max of "  << a << " and " << b << " is " <<  max<int>(a, b) << std::endl;
	std::cout << "Max of "  << a << " and " << b << " is " <<  max(a, b) << std::endl;

	float c = 21.0f;
	float d = 42.0f;

	std::cout << " Max of  " << c <<  " and " << d << " is " << max<float>(c, d) << std::endl;
	std::cout << " Max of  " << c <<  " and " << d << " is " << max(c, d) << std::endl;

	char e = 42;
	char f = 93;

	std::cout << "Max of "  << e << " and " << f << " is " <<  max<char>(e, f) << std::endl;
	std::cout << "Max of "  << e << " and " << f << " is " <<  max(e, f) << std::endl;

	// but...
	std::cout << "Max of "  << foo(a) << " and " << foo(a) << " is " <<  max<int>(foo(a), foo(b)) << std::endl;
	std::cout << "Max of "  << foo(a) << " and " << foo(a) << " is " <<  max(foo(a), foo(b)) << std::endl;

	return 0;
}
