#include "Ice.hpp"

Ice::Ice( ) {
	std::cout << "Ice constructor called  " << std::endl;
}

Ice::Ice( Ice const & src ) {
	std::cout << "Ice copy constructor called  " << std::endl;
	*this = src;
}

Ice &	Ice::operator=( Ice const & rhs ) {
	this->AMateria::operator=( rhs );
}

Ice::~Ice( ) {
	std::cout << "Ice called  " << std::endl;
}

void Ice::use(ICharacter & target) {
	this->AMateria::use( target );
}	
