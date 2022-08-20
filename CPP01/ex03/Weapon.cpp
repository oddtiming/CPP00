#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type) {
	return ;
}

Weapon::~Weapon( void ) {

	std::cout << "\n\t" << "Weapon \"" << this->_type 
		<< "\" has been destroyed" << std::endl;
	return ;
}

std::string Weapon::getType( void ) {

	return this->_type;
}

void		Weapon::setType( std::string type ) {

	this->_type = type;
	return ;
}
