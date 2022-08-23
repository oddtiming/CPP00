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
}

Cure::~Cure( ) {
	std::cout << "Cure called  " << std::endl;
}

void Cure::use(ICharacter & target) {
	this->AMateria::use( target );
}	
