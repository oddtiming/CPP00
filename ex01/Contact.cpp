#include <iostream>
#include "Contact.hpp"

Contact::Contact( void ) {
	return ;
}

Contact::Contact( std::string firstName,
				  std::string lastName,
				  std::string nickname,
				  std::string phoneNumber,
				  std::string darkestSecret ) :
				  _firstName(firstName),
				  _lastName(lastName),
				  _nickname(nickname),
				  _phoneNumber(phoneNumber),
				  _darkestSecret(darkestSecret) {
	return ;
}

Contact::~Contact( void ) {
	return ;
}

std::string	Contact::getFirstName( void ) const { return this->_firstName; }
std::string	Contact::getLastName( void ) const { return this->_lastName; }
std::string	Contact::getNickname( void ) const { return this->_nickname; }
std::string	Contact::getPhoneNumber( void ) const { return this->_phoneNumber; }
std::string	Contact::getDarkestSecret( void ) const { return this->_darkestSecret; }

void		Contact::setFirstName( std::string input ) {
	 std::cout << "entered " << __FUNCTION__ << "()" << std::endl;
	 this->_firstName = input; }
void		Contact::setLastName( std::string input ) { this->_lastName = input; }
void		Contact::setNickname( std::string input ) { this->_nickname = input; }
void		Contact::setPhoneNumber( std::string input ) { this->_phoneNumber = input; }
void		Contact::setDarkestSecret( std::string input ) { this->_darkestSecret = input; }
