#include <iostream>
#include <string>

class Student {

private:

	std::string	_login;

public:

	Student( void ) : _login( "ldefault" ) { 

		std::cout << "Student \"" << this->_login << "\" has successfully been created" << std::endl;
		return;
	}

	~Student( void ) { 

		std::cout << "Student \"" << this->_login << "\" has successfully been destroyed" << std::endl;
		return;
	}

};
