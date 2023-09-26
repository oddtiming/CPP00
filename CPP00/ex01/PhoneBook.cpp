#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) : _nbContacts( 0 ), _oldestContactIndex( 0 )  { return ; }
PhoneBook::~PhoneBook( void ) { return ; }

	/*******************************/
	/*   Public member functions   */
	/*******************************/

void	PhoneBook::addContact( void ) {

	// Prompt user for confirmation if list is full
	if (_nbContacts == MAX_CONTACTS 
			&& ask_yn("List full. Overwrite a contact?") == false)
		return;


	_setNextContactIndex();
	PhoneBook::_setField( "First name: ", &Contact::setFirstName );
	PhoneBook::_setField( "Last name: ", &Contact::setLastName );
	PhoneBook::_setField( "Nickname: ", &Contact::setNickname );
	PhoneBook::_setField( "Phone number: ", &Contact::setPhoneNumber );
	PhoneBook::_setField( "Aaaand darkest secret. Don't hold back: ", &Contact::setDarkestSecret );

	return ;
}

void	PhoneBook::searchContacts( void ) const {

	// Check whether the request can be processed
	if (_nbContacts == 0) {

		std::cout << "\tSorry, there are currently no contacts" << std::endl;
		return ;
	}

	// Display contacts
	_printContactsList();

	// Prompt user for contact index
	std::cout << "Please enter the index of the contact you're interested in: ";

	// Read input
	std::string	indexString;
	std::getline(std::cin >> std::ws, indexString);

	// Protection for ctrl-D
	if (indexString.empty())
		exit_phonebook();


	// Convert input and verify
	int		index;
	try {

		index = stoi( indexString );
	}

	// This try catch block seemed necessary after control chars made stoi() abort
	catch (const std::exception& e) {

		std::cerr << "\nYou done fucked up that input\n" << std::endl;
		return searchContacts();
	}

	if (index >= _nbContacts || index < 0) {
		std::cout << "\n\t***invalid index***\n" << std::endl;
		return searchContacts();
	}

	// Display all selected contact's fields
	_printContactFields( (index + _oldestContactIndex) % _nbContacts );

	return ;
}

	/************************/
	/*   Helper functions   */
	/************************/

void	PhoneBook::_setField( std::string prompt, void (Contact::*setterPtr)(std::string) ) {

	std::cout << prompt;
	std::string	buffer;
	
	// using std::getline() here gives us two advantages:
	// 1) reads entire line
	// 2) accepts input manipulators, 
	// 		here std::ws to discard leading whitespaces,
	//		and thus allow multiple inputs in a row.
	std::getline(std::cin >> std::ws, buffer);

	// To account for ctrl-D
	if (buffer.empty())
		exit_phonebook();

	(_Contacts[_currentIndex].*setterPtr)(buffer);
}

void	PhoneBook::_setNextContactIndex( void ) {

	// If the phoneBook is not full, we can simply add sequentially
	if (_nbContacts < MAX_CONTACTS) {

		_currentIndex = _nbContacts;
		_nbContacts++;
		return ;
	}

	// if phoneBook is full, replace oldest entry
	_currentIndex = _oldestContactIndex;

	// Update the oldest entry to next oldest
	_oldestContactIndex += 1;
	_oldestContactIndex %= MAX_CONTACTS;

	return ;
}


	/*********************************/
	/*  Printing and Util functions  */
	/*********************************/

void	PhoneBook::_printContactFields( int index ) const {

	std::cout << "First name: \t"
		<< _Contacts[index].getFirstName() << "\n";

	std::cout << "Last name: \t"
		<< _Contacts[index].getLastName() << "\n";

	std::cout << "Nickname: \t"
		<< _Contacts[index].getNickname() << "\n";

	std::cout << "Phone number: \t"
		<< _Contacts[index].getPhoneNumber() << "\n";

	std::cout << "Darkest secret: "
		<< _Contacts[index].getDarkestSecret() << "\n";
	
	return ;
}

static void	_formatContactListField( std::string str) {

	if (str.length() <= 10) {

		for (int i = str.length(); i < 10; i++)
			std::cout << " ";
		std::cout << str;
	}
	else {

		std::cout << str.substr(0, 9);
		std::cout << ".";
	}
	return ;
}

static void _printBorder( void ) {

	for (int i = 0; i < 45; i++) // 45 = 4 fields of 10 chars + 5 separators 
		std::cout << "-";
	std::cout << "\n";
}

/**
 * 		Used by PhoneBook::searchContacts() to display the bare minimum
 * 		of info for the user to pick a contact.
 */
void	PhoneBook::_printContactsList( void ) const {

	_printBorder();
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First name";
	std::cout << "|" << std::setw(10) << "Last name";
	std::cout << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	_printBorder();

	for (int i = 0; i < _nbContacts; i++) {

		// To account for the fact that contacts are overwritten sequentially
		// in rotation, but are displayed from oldest to newest.
		int		convertedIndex = (_oldestContactIndex + i) % _nbContacts;

		std::cout << "|" << std::setw(10) << i;
		std::cout << "|";
		_formatContactListField( _Contacts[convertedIndex].getFirstName() );
		std::cout << "|";
		_formatContactListField( _Contacts[convertedIndex].getLastName() );
		std::cout << "|";
		_formatContactListField( _Contacts[convertedIndex].getNickname() );
		std::cout << "|" << std::endl;
	}
	_printBorder();

	return ;
}


/**
 * 		Disgrace of a function, but it's only for testing purposes
 * 		NOTE: @correcteur : do you know how to batch initialize
 * 			 a list of objects without using the `new' keyword?
 */
void	PhoneBook::generateData( void ) {

	std::string	fakePhone("+1 (514) 555-0123");

	_Contacts[0].setFirstName("Samantha");
	_Contacts[0].setLastName("Doe");
	_Contacts[0].setNickname("Sam");
	_Contacts[0].setPhoneNumber("+1 (514) 555-0123");
	_Contacts[0].setDarkestSecret("Ate Play Doe.");

	_Contacts[1].setFirstName("Robert");
	_Contacts[1].setLastName("Smith");
	_Contacts[1].setNickname("Bob");
	_Contacts[1].setPhoneNumber("+1 (514) 555-0123");
	_Contacts[1].setDarkestSecret("Bob's his uncle.");

	_Contacts[2].setFirstName("Louis-Alexandre");
	_Contacts[2].setLastName("Tremblay");
	_Contacts[2].setNickname("Lou");
	_Contacts[2].setPhoneNumber("+1 (514) 555-0123");
	_Contacts[2].setDarkestSecret("Y'est pourri au hockey.");

	_Contacts[3].setFirstName("Jabreakit");
	_Contacts[3].setLastName("Jubaydit");
	_Contacts[3].setNickname("JJ Breaks");
	_Contacts[3].setPhoneNumber("+1 (514) 555-0123");
	_Contacts[3].setDarkestSecret("Clumsy af.");

	_Contacts[4].setFirstName("Gal");
	_Contacts[4].setLastName("Gadonut");
	_Contacts[4].setNickname("The Incredible Hole");
	_Contacts[4].setPhoneNumber("+1 (514) 555-0123");
	_Contacts[4].setDarkestSecret("Straight up stealing from Impractical Jokers.");

	_Contacts[5].setFirstName("Smallmedium");
	_Contacts[5].setLastName("Fat");
	_Contacts[5].setNickname("Biggie");
	_Contacts[5].setPhoneNumber("+1 (514) 555-0123");
	_Contacts[5].setDarkestSecret("Hasn't drank water in 5 years.");

	_Contacts[6].setFirstName("Coach");
	_Contacts[6].setLastName("Grapefruit");
	_Contacts[6].setNickname("Sourface");
	_Contacts[6].setPhoneNumber("+1 (514) 555-0123");
	_Contacts[6].setDarkestSecret("Isn't a real coach.");

	_Contacts[7].setFirstName("Monsieur");
	_Contacts[7].setLastName("Guilis");
	_Contacts[7].setNickname("Guigui");
	_Contacts[7].setPhoneNumber("+1 (514) 555-0123");
	_Contacts[7].setDarkestSecret("Très chatouilleux.");

	_nbContacts = 8;

	std::cout << "\n\t8 friendly people successfully added to My Awesome PhoneBook®!\n" << std::endl;

	return ;
}
