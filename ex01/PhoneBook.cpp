#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) : _nbContacts( 0 ), _oldestContactIndex( 0 )  {
	return ;
}

PhoneBook::~PhoneBook( void ) {
	return ;
}

bool	ask_yn( std::string prompt ) {

	// Display the prompt
	std::cout << prompt;
	std::cout << " y/n : ";

	// Read the answer
	char	c;
	std::cin >> c;

	// Verify the input
	if (c != 'y' && c != 'n') {
		std::cout << "Please enter a y/n answer" << "\n";
		return ask_yn( prompt );
	}

	return c == 'y' ? true : false;
}

void	PhoneBook::searchContacts( void ) const {

	_printContactsList();

	int	index;

	std::cin >> index;
	if (index > _nbContacts && index < 0) {
		std::cout << "\n\t***invalid index***\n" << std::endl;
		return searchContacts();
	}

	_printContactFields( index );

	return ;
}

void	PhoneBook::addContact( void ) {

	// Prompt user for confirmation if list is full
	if (this->_nbContacts == MAX_CONTACTS 
			&& ask_yn("List full. Overwrite a contact?") == false)
		return;


	this->_setNextContactIndex();

	std::cout << "First name: ";
	PhoneBook::_setField( &Contact::setFirstName );

	std::cout << "Last name: ";
	PhoneBook::_setField( &Contact::setLastName );

	std::cout << "Nickname: ";
	PhoneBook::_setField( &Contact::setNickname );

	std::cout << "Phone number: ";
	PhoneBook::_setField( &Contact::setPhoneNumber );

	std::cout << "Aaaand darkest secret. Don't hold back: " << std::endl;
	PhoneBook::_setField( &Contact::setDarkestSecret );

	return ;
}

void	PhoneBook::_setField( void (Contact::*setterPtr)(std::string) ) {

	std::string	buffer;
	
	// using std::getline() here gives us two advantages:
	// 1) reads entire line
	// 2) accepts input manipulators, 
	// 		here std::ws to discard leading whitespaces,
	//		and thus allow multiple inputs in a row.
	std::getline(std::cin >> std::ws, buffer);

	(_Contacts[_currentIndex].*setterPtr)(buffer);
}

void	PhoneBook::_printContactFields( int index ) const {

	std::cout << "First name: ";
	std::cout << _Contacts[index].getFirstName() << "\n";

	std::cout << "Last name: ";
	std::cout << _Contacts[index].getLastName() << "\n";

	std::cout << "Nickname: ";
	std::cout << _Contacts[index].getNickname() << "\n";

	std::cout << "Phone number: ";
	std::cout << _Contacts[index].getPhoneNumber() << "\n";

	std::cout << "Darkest secret: ";
	std::cout << _Contacts[index].getDarkestSecret() << "\n";
	
	return ;
}

void	PhoneBook::_printContactsList( void ) const {

	std::cout << "|" << "First name";
	std::cout << "|" << " Last name";
	std::cout << "|" << "  Nickname";
	std::cout << "|" << "Phone numb";
	std::cout << "|" << "DarkSecret" << "|" << std::endl;

	return ;
}


void	PhoneBook::_setNextContactIndex( void ) {

	if (this->_nbContacts < MAX_CONTACTS) {

		this->_currentIndex = this->_nbContacts;
		this->_nbContacts++;
		return ;
	}

	// Store the next available contact
	this->_currentIndex = this->_oldestContactIndex;

	// Update the oldest contact to next oldest
	this->_oldestContactIndex += 1;
	this->_oldestContactIndex %= MAX_CONTACTS;

	return ;
}

void	PhoneBook::generateData( void ) {

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

	return ;
}
