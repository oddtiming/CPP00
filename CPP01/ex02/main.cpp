#include <iostream>		// std::cout, std::endl

int	main( void ) {

	std::string		string( "HI THIS IS BRAIN!" );
	std::string*	stringPtr = &string;
	std::string&	stringRef = string;


	// I have no idea why they are the same 
	std::cout << "&string:  	" << &string << "\n";
	std::cout << "&stringPtr:	" << &stringPtr << "\n";
	std::cout << "&stringRef:	" << &stringRef << "\n\n";

	std::cout << "string:		" << string << "\n";
	std::cout << "*stringPtr:	" << *stringPtr << "\n";
	std::cout << "stringRef:	" << stringRef << std::endl;

	return 0;
}
