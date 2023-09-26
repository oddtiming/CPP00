#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name) {
	return ;
}

Zombie::~Zombie( void ) {
 	std::cout << this->_name << " died atrociously. sad." << std::endl;
	return ;
}

void	Zombie::announce( void ) const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

std::string const &	Zombie::getName( void ) const {
	return this->_name;
}
