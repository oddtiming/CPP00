#pragma once

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {

public:

	PhoneBook( void );
	~PhoneBook( void );

	/* Methods */
	void	generateData( void );
	void	searchContacts( void ) const;
	void	addContact( void );
	

private:

	/* Attributes */
	Contact	_Contacts[MAX_CONTACTS];
	int		_nbContacts;
	int		_currentIndex;
	int		_oldestContactIndex;	// To print from oldest to newest

	/* Methods */
	void	_setField( void (Contact::*setterPtr)( std::string ) );
	void	_printContactFields( int index ) const;
	void	_printContactsList( void ) const;
	void	_setNextContactIndex( void );

};
