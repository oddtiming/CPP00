#include <iostream>		// For std::cout, std::endl
#include "HumanB.hpp"

HumanB::HumanB( std::string name) : _name(name) {
	return ;
}

HumanB::~HumanB( void ) {

	std::cout << "\n\t" << "HumanB \"" << this->_name 
		<< "\" has been destroyed" << std::endl;
	return ;
}

void	HumanB::setWeapon( Weapon& weapon ) {

	this->_weapon = &weapon;
	return ;
}


void	HumanB::attack( void ) {

	std::cout << "\n\t" << "\"" << _name << "\" attacks with the \""
		<< _weapon->getType() << "\". It's very effective!" << std::endl;
	return ;
}
