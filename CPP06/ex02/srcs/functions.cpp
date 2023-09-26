#include "Classes.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

long long getTimeInNanoseconds( );

Base *	generate(void) {

	srand( static_cast< unsigned int >(getTimeInNanoseconds()));

	switch ( rand() % 3 ) {
		case 0:
			std::cout << "* Generated class A *" << std::endl;
			return new A();
		case 1:
			std::cout << "* Generated class B *" << std::endl;
			return new B();
		case 2:
			std::cout << "* Generated class C *" << std::endl;
			return new C();
		default:
			return nullptr;
	}
}

void	identify(Base * p) {

	cout << "Base * p is Class\t: ";
	cout << ( dynamic_cast< A * >( p ) ? "A" : "" );
	cout << ( dynamic_cast< B * >( p ) ? "B" : "" );
	cout << ( dynamic_cast< C * >( p ) ? "C" : "" );
	cout << endl;
}

void	identify(Base & p) {
	
	cout << "Base & p is Class\t: ";
	
	try {
		A & child = dynamic_cast< A & >( p );
		cout << "A" << endl;
		return ((void) child);
	}
	catch (std::exception &e) { }

	try {
		B & child = dynamic_cast< B & >( p );
		cout << "B" << endl;
		return ((void) child);
	}
	catch (std::exception &e) { }
	
	try {
		C & child = dynamic_cast< C & >( p );
		cout << "C" << endl;
		return ((void) child);
	}
	catch (std::exception &e) { }	
}
