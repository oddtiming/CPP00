#include "Water.hpp"

Water::Water( ) {
	std::cout << "Water constructor called  " << std::endl;
}

Water::Water( Water const & src ) {
	std::cout << "Water copy constructor called  " << std::endl;
	*this = src;
}

Water &	Water::operator=( Water const & rhs ) {
	this->AMateria::operator=( rhs );
	return *this;
}

Water::~Water( ) {
	std::cout << "Water called  " << std::endl;
}


void	Water::use( ICharacter& target ) {
	return this->AMateria::use( target );	
}

AMateria* Water::clone() const {
	
	Water *	clone = new Water();
	
	*clone = *this;

	return clone;
}
