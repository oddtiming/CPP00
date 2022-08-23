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
}

Water::~Water( ) {
	std::cout << "Water called  " << std::endl;
}

void Water::use(ICharacter & target) {
	this->AMateria::use( target );
}	
