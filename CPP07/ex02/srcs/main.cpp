#include "Array.tpp"
#include "Array.hpp"
#include "iter.hpp"
#include "Vertex.tpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;
void	flipBool( bool & b ) {
	b = !b;
}

int	main( ) {

	Array< int > 				a( 10 );
	Array< float > 				b( 10 );
	Array< string > 			c( 10 );
	Array< bool > 				d( 10 );
	Array< Vertex< int > >		e( 10 );
	

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;

	::iter( d.getData(), 10, flipBool);

	cout << d << endl;

	int i = 3;
	Array< int > *				f = new Array< int >( 10, i );
	cout << *f << endl;
	Array< int > 				g = *f;
	cout << g << endl;
	Array< int > 				h;
	h = *f;
	cout << h << endl;

	delete f;
	cout << g << endl;
	cout << h << endl;

	try {
		cout << g[11];
	} catch (std::exception & e) {
		std::cerr << e.what() << endl;
	}	

	try {
		cout << g[-1];
	} catch (std::exception & e) {
		std::cerr << e.what() << endl;
	}
	

	return 0;

}