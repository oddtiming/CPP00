#include "Fire.hpp"

Fire::Fire( ) {
	std::cout << "Fire constructor called  " << std::endl;
}

Fire::Fire( Fire const & src ) {
	std::cout << "Fire copy constructor called  " << std::endl;
	*this = src;
}

Fire &	Fire::operator=( Fire const & rhs ) {
	this->AMateria::operator=( rhs );
	return *this;
}

Fire::~Fire( ) {
	std::cout << "Fire called  " << std::endl;
}


void	Fire::use( ICharacter& target ) {
	return this->AMateria::use( target );	
}

AMateria* Fire::clone() const {
	
	Fire *	clone = new Fire();
	
	*clone = *this;

	return clone;
}
