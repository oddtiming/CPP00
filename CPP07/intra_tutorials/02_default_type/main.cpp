#include "Vertex.tpp"
#include <iostream>

int	main( ) {

	Vertex< int >		a( 42, 21, 84 );
	Vertex< float >		b( -8.73f, 9, 8.3f );
	Vertex< bool >		c( true, false, true );
	Vertex<>			d( 2, 3, 3 );


	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;

	return 0;

}
