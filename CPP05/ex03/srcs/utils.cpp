#include <iostream>
#include <string>
#include <stdexcept>

// If Ctrl-D is hit, all following calls will return false
bool	ask_yn( std::string prompt ) {
	// Display the prompt
	std::cout << prompt;
	std::cout << " y/n : ";
	// Read the answer
	char	c = 0;
	std::cin >> c;
	// Verify the input
	if (c && c != 'y' && c != 'n') {
		std::cout << "Please enter a y/n answer" << std::endl;
		return ask_yn( prompt );
	}
	return c == 'y' ? true : false;
}


std::string	cleanString(std::string str) {

	std::string clean;
	id_t		i = 0;
	
	while ( isspace(str[i]) )
		i++;

	while ( i < str.length() ) {

		clean += tolower(str[i++]);	

		while (isspace(str[i]))
			i++;
	}
	if ( clean.at( clean.length() - 1 ) == ' ' )
		clean.erase( clean.length() - 1 );

	return clean;
}


void	displErr( std::exception & e ) {
	std::cerr << "\n" << e.what() << std::endl;
}

