#include <iostream>		// For std::cout, std::endl
#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : 
	_name(name),
	_weapon(weapon) {
	return ;
}

HumanA::~HumanA( void ) {

	std::cout << "\n\t" << "HumanA \"" << this->_name 
		<< "\" has been destroyed" << std::endl;
	return ;
}

void	HumanA::attack( void ) {

	std::cout << "\n\t" << "\"" << _name << "\" attacks with the \""
		<< _weapon.getType() << "\". It's very effective!" << std::endl;
	return ;
}
