#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name) {
	return ;
}

Zombie::Zombie( void ) {
	return ;
}

Zombie::~Zombie( void ) {
 
	std::cout << this->_name << " died atrociously. sad." << std::endl;
 
	return ;
}


void	Zombie::announce( void ) {

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;

	return ;
}

std::string	Zombie::getName( void ) {
	return this->_name;
}

void		Zombie::setName( std::string name ) {
	this->_name = name;
}
