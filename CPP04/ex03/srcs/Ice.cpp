c#include "Ice.hpp"

Ice::Ice( )  {
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
	std::cout << "Ice called  " << std::endl;
}


void	Ice::use( ICharacter& target ) {
	return this->AMateria::use( target );
}

AMateria* Ice::clone() const {

	Ice *	clone = new Ice();
	
	*clone = *this;

	return clone;
}	
