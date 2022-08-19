#include <iostream>
#include <string>

class Student {

private:

	std::string	_login;

public:

	Student( std::string const & login ) : _login( login ) { 

		std::cout << "Student \"" << this->_login << "\" has successfully been created" << std::endl;
		return;
	}

	~Student( void ) { 

		std::cout << "Student \"" << this->_login << "\" has successfully been destroyed" << std::endl;
		return;
	}

	
	std::string			*getPtr( void ) {
		return &(this->_login);
	}

	std::string const	*getConstPtr( void ) const {
		return &(this->_login);
	}

	std::string		&getRef( void ) {
		return this->_login;
	}

	std::string const &	getConstRef( void ) const {
		return this->_login;
	}

};

int	main( void ) {
	
	Student jim( "jim" );
	Student const bob( "bob" );

	std::cout << "bob.getConstRef(): " << bob.getConstRef()  << "\t\tjim.getConstRef(): " << jim.getConstRef()<< std::endl;
	std::cout << "*(bob.getConstPtr()): " << *(bob.getConstPtr())  << "\t*(jim.getConstPtr()): " << *(jim.getConstPtr())<< std::endl;


	jim.getRef() = "not jim anymore";
	std::cout << "\tjim.getConstRef(): " << jim.getConstRef()<< std::endl;
	std::cout << "\t*(jim.getConstPtr()): " << *(jim.getConstPtr())<< std::endl;
	
	*(jim.getPtr()) = "jim is now bob?";
	std::cout << "\tjim.getConstRef(): " << jim.getConstRef()<< std::endl;
	std::cout << "\t*(jim.getConstPtr()): " << *(jim.getConstPtr())<< std::endl;

	// Here, only jim can be dereferenced, since bob is a const object
	// Const functions can be called on non-const objs, but not the other way around

	return 0;
}
