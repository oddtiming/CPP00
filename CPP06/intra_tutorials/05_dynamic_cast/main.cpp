#include <iostream>

// dynamic_cast allows you to interpret the variable at run time. 
// This means that failure will not be known at compile time

// You need to be able to handle dynamic_cast exceptions at runtime


/**
 * 		NOTE: Only works on a polymorphic instance !
 * 		one of the member functions needs to be virtual
 * 
 * 		also only works on a downcast
 * 
 */

class Parent				{ public: virtual ~Parent() {} };

class Child1: public Parent	{};
class Child2: public Parent	{};

class Other					{};

int	main( ) {

	Child1	a;				// ref value
	Parent	*b = &a;		// Implicit upcast		-> OK


	std::cout << "Child1	a;		" << std::endl;
	std::cout << "Parent	*b = &a;" << std::endl;


	// Explicit downcast
	//	This works
	Child1 * c = dynamic_cast<Child1 *>(b);
	if ( c == NULL ) {
		std::cout << "didn't work" << std::endl;
	}	
	else {
		std::cout << "dynamic_cast<Child1 *>(b) worked!" << std::endl;
	}	

	// Explicit downcast to wrong type
	//	returns null
	Child2 * e = dynamic_cast<Child2 *>(b);
	if ( e == NULL ) {
		std::cout << "dynamic_cast<Child2 *>(b) didn't work" << std::endl;
	}	
	else {
		std::cout << "dynamic_cast<Child2 *>(b) worked!" << std::endl;
	}	

	// Explicit downcast
	//	This works
	Other * f = dynamic_cast<Other *>(b);
	if ( f == NULL ) {
		std::cout << "dynamic_cast<Other *>(b) didn't work" << std::endl;
	}	
	else {
		std::cout << "dynamic_cast<Other *>(b) worked!" << std::endl;
	}	

	// Explicit downcast. it's allowed, but will it work..?
	// Doesn't work!
	try {

		Child2 &	d = dynamic_cast<Child2 &>(*b);
		std::cout << "dynamic_cast<Child2 &>(*b) worked!" << std::endl;
	}
	catch(std::bad_cast & e) {
		std::cout << "dynamic_cast<Child2 &>(*b) didn't work: " << e.what() << std::endl;
	}

	// Explicit downcast. it's allowed, but will it work..?
	//	This works, known conversion
	try {

		Child1 &	d = dynamic_cast<Child1 &>(*b);
		std::cout << "dynamic_cast<Child1 &>(*b) worked!" << std::endl;
	}
	catch(std::exception & e) {
		std::cout << "dynamic_cast<Child1 &>(*b) didn't work" << std::endl;

	}

	return 0;
}
