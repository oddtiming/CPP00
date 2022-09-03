#include <iostream>		// For std::cout, std::endl
#include "HumanB.hpp"

HumanB::HumanB( std::string name) : 
	_name(name),
	_weapon(nullptr)
{
	return ;
}

HumanB::~HumanB( void ) {

	std::cout << "\n\t" << "HumanB \"" << this->_name 
		<< "\" has been destroyed" << std::endl;
	return ;
}

void	HumanB::setWeapon( Weapon& weapon ) {

	std::cout << "\n\t\"" 
			  << _name 
			  << "\" picks up the \""
			  << weapon.getType() 
			  << "\"." << std::endl;

	this->_weapon = &weapon;
	return ;
}


void	HumanB::attack( void ) const {

	if ( _weapon == nullptr ) {
		std::cout << "\n\t\"" 
				  << _name 
				  << "\" cannot attack, he is weaponless!" 
				  << std::endl;
		return ;
	}

	std::cout << "\n\t\"" 
			  << _name 
			  << "\" attacks with the \""
			  << _weapon->getType() 
			  << "\". It's very effective!" 
			  << std::endl;
	return ;
}
