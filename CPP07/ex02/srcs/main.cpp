#include "Array.tpp"
#include "Array.hpp"
#include "iter.hpp"
#include "Vertex.tpp"
#include <iostream>


void	_print_header( std::string const & text );

using std::cout;
using std::endl;
using std::string;
void	flipBool( bool & b ) {
	b = !b;
}

template <typename T>
void	print( T const & i ) {
	cout << i << endl;
}

int	main( ) {

	_print_header("Part 1 : General tests");
	
	bool					boolTrue = true;
	string					str = "patate";
	int						i1 = 42;
	float					f1 = 42.0f;
	Vertex<float>			v1( f1, f1, f1 );
	Array< int > 			a( 10, i1 );
	Array< int > 			a1;
	Array< float > 			b( 12, f1 );
	Array< string > 		c( 2, str );
	Array< bool > 			d( 9, boolTrue );
	Array< Vertex<float> >	e( 8, v1 );


	cout << "Array< int > 			a( 10 ) \n"	<< a;
	cout << "size: " 							<< a.size()	<< "\n" << endl;
	cout << "a[5]				: "				<< a[5]		<< endl;
	cout << "Array< int > 			a1 \n"		<< a1;
	cout << "size: " 							<< a1.size()<< "\n" << endl;
	cout << "Array< float > 		b( 10 ) \n"	<< b;
	cout << "size: " 							<< b.size()	<< "\n" << endl;
	cout << "Array< string > 		c( 10 ) \n"	<< c;
	cout << "size: " 							<< c.size()	<< "\n" << endl;
	cout << "Array< bool > 			d( 10 ) \n"	<< d;
	cout << "size: " 							<< d.size()	<< "\n" << endl;
	cout << "Array< Vertex< int > >	e( 10 ) \n";
	::iter(e.getData(), e.size(), print);
	cout << "size: " 							<< e.size()	<< "\n" << endl;

	::iter( d.getData(), 10, flipBool);

	cout << d << endl;



	_print_header("Part 2 : copy tests");

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



	
	_print_header("Part 3 : out of bounds exception");

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

void	_print_header( std::string const & text ) {
	uint len = text.length();
	
	std::cout << "\n" << std::setw(len * 3 + 5) << std::setfill('*') << "\n";
	std::cout << std::setw(len + 2) << std::setfill(' ') << "* " << text << " *" << "\n";
	std::cout << std::setw(len * 3 + 5) << std::setfill('*') << "\n" << std::endl;
}
