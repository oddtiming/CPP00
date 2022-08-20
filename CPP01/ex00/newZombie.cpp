#include "Zombie.hpp"

/**
 * @brief Allocates a zombie with name `name' and returns its pointer
 * 
 * @return Zombie* needs to be freed
 */
Zombie*	newZombie( std::string name ) { return new Zombie( name ); }
