#pragma once

#include <string>

class Contact {

public:

	Contact( void );
	Contact( std::string firstName,
			 std::string lastName,
			 std::string nickname,
			 std::string phoneNumber,
			 std::string darkestSecret );
	~Contact( void );

	std::string	getFirstName( void ) const;
	std::string	getLastName( void ) const;
	std::string	getNickname( void ) const;
	std::string	getPhoneNumber( void ) const;
	std::string	getDarkestSecret( void ) const;

	void		setFirstName( std::string input );
	void		setLastName( std::string input );
	void		setNickname( std::string input );
	void		setPhoneNumber( std::string input );
	void		setDarkestSecret( std::string input );


private:

	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

};
