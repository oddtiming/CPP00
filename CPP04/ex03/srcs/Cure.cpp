#include "Cure.hpp"

Cure::Cure( ) {
	std::cout << "Cure constructor called  " << std::endl;
}

Cure::Cure( Cure const & src ) {
	std::cout << "Cure copy constructor called  " << std::endl;
	*this = src;
}

Cure &	Cure::operator=( Cure const & rhs ) {
	this->AMateria::operator=( rhs );
	return *this;
}

Cure::~Cure( ) {
	std::cout << "Cure called  " << std::endl;
}

void	Cure::use( ICharacter& target ) {
	return this->AMateria::use( target );	
}

AMateria* Cure::clone() const {
	
	Cure *	clone = new Cure();
	
	*clone = *this;

	return clone;
}
