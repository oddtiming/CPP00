#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

bool	ask_yn( std::string prompt ) {

	// Display the prompt
	std::cout << prompt;
	std::cout << " y/n : ";

	// Read the answer
	char	c = 0;
	std::cin >> c;

	// Verify the input
	// If ctrl-D is hit, it is taken as a negative answer
	if (c && c != 'y' && c != 'n') {
		std::cout << "Please enter a y/n answer" << std::endl;
		return ask_yn( prompt );
	}

	return c == 'y' ? true : false;
}

void	exit_phonebook( void ) {

	std::cout << "\n" << "My Awesome PhoneBook® says bye bye!" << std::endl;

	exit(EXIT_SUCCESS);
}

void	_loop( PhoneBook& phoneBook )
{
	std::cout << "What do you want to do? ADD, SEARCH, or EXIT: ";

	std::string	input;
	std::getline(std::cin >> std::ws, input);

	if (input.compare( "ADD" ) == 0)
		phoneBook.addContact();
		
	else if (input.compare( "SEARCH" ) == 0)
		phoneBook.searchContacts();

	// Ctrl-D is treated as end of program
	else if (input.empty() || input.compare( "EXIT" ) == 0)
		return exit_phonebook() ;
		
	else 
		std::cout << "Invalid input" << std::endl;

	return _loop( phoneBook );
}

int	main( void ) {

	PhoneBook phoneBook;

	std::cout << "Welcome My Awesome PhoneBook®" << "\n";

	if (ask_yn("Do you want to pregenerate a phone book?"))
		phoneBook.generateData();

	_loop( phoneBook );


	return 0;
}
