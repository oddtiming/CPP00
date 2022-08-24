#include "Ice.hpp"

Ice::Ice( ) : AMateria( "ice" ) {
	std::cout << "Ice constructor called  " << std::endl;
}

Ice::Ice( Ice const & src ) {
	std::cout << "Ice copy constructor called  " << std::endl;
	*this = src;
}

Ice &	Ice::operator=( Ice const & rhs ) {
	this->AMateria::operator=( rhs );
	return *this;
}

Ice::~Ice( ) {
	std::cout << "~Ice destructor called  " << std::endl;
}


void	Ice::use( ICharacter& target ) {
	std::cout << "\n* " 
		<< "shoots an ice bolt at " << target
		<< " *" << std::endl;
}

AMateria* Ice::clone() const {

	Ice *	clone = new Ice();
	
	*clone = *this;

	return clone;
}	
