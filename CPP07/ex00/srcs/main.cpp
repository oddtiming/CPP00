#include "functions.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;


int main( void ) {
	int a = 2;
	int b = 3;
	
	cout << "a = " << a << ", b = " << b << endl;
	::swap(a, b);

	cout << "\tafter ::swap()" << endl;
	cout << "a = " << a << ", b = " << b << endl;
	
	cout << "min( a, b ) = " << ::min( a, b ) << endl;
	cout << "max( a, b ) = " << ::max( a, b ) << endl;
	
	string c = "chaine1";
	string d = "chaine2";
	
	cout << "c = " << c << ", d = " << d << endl;
	::swap(c, d);
	
	cout << "\tafter ::swap()" << endl;
	cout << "c = " << c << ", d = " << d << endl;
	
	cout << "min( c, d ) = " << ::min( c, d ) << endl;
	cout << "max( c, d ) = " << ::max( c, d ) << endl;

	uint	e = 10;
	uint 	f = 10;

	cout << "e = " << e << ", f = " << f << endl;
	cout << "&e = " << &e << ", &f = " << &f << endl;

	cout << "&min(e, f) : " << &min(e, f) << " == &f: " << &f << endl;
	cout << "&max(f, e) : " << &max(f, e) << " == &e: " << &e << endl;

	return 0;
}