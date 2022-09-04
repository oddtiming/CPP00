#include "Cure.hpp"

Cure::Cure( ) : AMateria( "cure" ) {
	std::cout << "Cure constructor called  " << std::endl;
}

Cure::Cure( Cure const & src ) {
	(void) src;
	// std::cout << "Cure copy constructor called  " << std::endl;
	// *this = src;
}

Cure &	Cure::operator=( Cure const & rhs ) {
	(void) rhs;
	// this->AMateria::operator=( rhs );
	return *this;
}

Cure::~Cure( ) {
	std::cout << "~Cure destructor called" << std::endl;
}

void	Cure::use( ICharacter& target ) {
	std::cout << "\n* " 
			  << "heals " << target << "'s wounds"
			  << " *" << std::endl;
}

AMateria* Cure::clone() const {
	
	Cure *	clone = new Cure();
	
	// *clone = *this;

	return clone;
}
