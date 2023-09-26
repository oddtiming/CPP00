#include "Fire.hpp"

Fire::Fire( ) : AMateria( "fire" ) {
	std::cout << "Fire constructor called  " << std::endl;
}

Fire::Fire( Fire const & src ) {
	(void) src;
	// std::cout << "Fire copy constructor called  " << std::endl;
	// *this = src;
}

Fire &	Fire::operator=( Fire const & rhs ) {
	(void) rhs;
	// this->AMateria::operator=( rhs );
	return *this;
}

Fire::~Fire( ) {
	std::cout << "~Fire destructor called" << std::endl;
}

void	Fire::use( ICharacter& target ) {
	std::cout << "\n* "
			  << "burns "
			  << target
			  << " with the force of a thousand suns!"
			  << " *"
			  << std::endl;
}

AMateria* Fire::clone() const {
	
	Fire *	clone = new Fire();
	
	// *clone = *this;

	return clone;
}
