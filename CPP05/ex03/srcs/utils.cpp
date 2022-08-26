#include <iostream>
#include <iomanip>
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

std::string	strToLower(std::string str) {

	std::string toLower;
	size_t		i = 0;
	
	while ( i < str.length() ) {

		toLower += tolower(str[i++]);	
	}

	return toLower;
}


void	_displErr( std::exception & e ) {
	std::cerr << "\n" << e.what() << "\n" << std::endl;
}

void	_printHeader( std::string const & text ) {
	std::cout << "\n" << std::setw(40) << std::setfill('*') << "\n";
	std::cout << "\t* " << text << " *" << "\n";
	std::cout << std::setw(40) << std::setfill('*') << "\n" << std::endl;
}

bool	isQuitInput( std::string const & input ) {
	if ( input.empty() || input == "exit" || input == "EXIT"
			|| input == "quit" || input == "QUIT" ) {
		std::cout << "\n\tBye for now, boss!\n" << std::endl;
		return true;
	}
	return false;
}
