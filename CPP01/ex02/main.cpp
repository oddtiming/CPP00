#include <iostream>		// std::cout, std::endl

int	main( void ) {

	std::string		string( "HI THIS IS BRAIN" );
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;


	// I have no idea why they are the same 
	std::cout << "&string:  	" << &string << "\n";
	std::cout << "&stringPTR:	" << &stringPTR << "\n";
	std::cout << "&stringREF:	" << &stringREF << "\n\n";

	std::cout << "string:		" << string << "\n";
	std::cout << "*stringPTR:	" << *stringPTR << "\n";
	std::cout << "stringREF:	" << stringREF << std::endl;

	return 0;
}
