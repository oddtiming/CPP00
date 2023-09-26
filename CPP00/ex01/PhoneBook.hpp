#pragma once

#ifndef CPP00_EX01_PHONEBOOK_HPP
# define CPP00_EX01_PHONEBOOK_HPP


# include "Contact.hpp"

# define MAX_CONTACTS 8

/* Misc Function prototypes from main.cpp */
void	exit_phonebook( void );
bool	ask_yn( std::string prompt );

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
	int		_currentIndex;			// Kept it as an attribute for _setNextContactIndex()
	int		_oldestContactIndex;	// To print from oldest to newest

	/* Methods */
	void	_setField( std::string prompt, void (Contact::*setterPtr)( std::string ) );
	void	_printContactFields( int index ) const;
	void	_printContactsList( void ) const;
	void	_setNextContactIndex( void );

};

#endif	// CPP00_EX01_PHONEBOOK_HPP
