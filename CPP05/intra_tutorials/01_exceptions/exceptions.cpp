#include <iostream>
#include <string>
#include <stdexcept>


void	test1( ) {

	try {
		int i = 0;
		if ("i = 0") {
			throw std::exception();
		}
		else {
			std::cout << "well, well, well..." << std::endl;
		}
	}
	catch (std::exception& e) {
		std::cerr << "oops test1() " << std::endl;
	}
}



class TestException : public std::exception {

	public:
		virtual const char* what() const throw() {
			return ("TestException::what called");
		}
};



void	test2( ) {

	static bool i = false;

	i = !i;

	if ( i ) {
		throw std::exception();
	}
	if ( !i ) {
		throw TestException();
	}
	else {
		std::cout << "test3(): Shit." << std::endl;
	}
}

void	test3( ) {

	try {
		test2();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

}

void	test4( ) {

	try {
		test2();

	} catch (TestException& e) {
		std::cerr << e.what() << " Exception caught" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << " Exception caught" << std::endl;
	}
	
}

int	main( ) {

	test1();
	test4();
	test4();
	test3();

	return 0;
}

