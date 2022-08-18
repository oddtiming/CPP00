#include <iostream>
#include "PhoneBook.hpp"

bool	ask_yn( std::string prompt );

void	_loop( PhoneBook& phoneBook )
{
	std::cout << "What do you want to do? ADD, SEARCH, or EXIT: ";

	std::string	input;
	std::getline(std::cin >> std::ws, input);

	if (input.compare( "ADD" ) == 0)
		phoneBook.addContact();
	else if (input.compare( "SEARCH" ) == 0)
		phoneBook.searchContacts();
	else if (input.compare( "EXIT" ) == 0)
		return ;
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

	std::cout << "My Awesome PhoneBook says bye bye!" << std::endl;

	return 0;
}
