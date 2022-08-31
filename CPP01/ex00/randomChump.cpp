#include "Zombie.hpp"

/**
 * 		Allocates a zombie, makes it announce itself, and returns its pointer
 */
void	randomChump( std::string name ) {
	Zombie	randomChump( name );

	randomChump.announce();
	
	return ;
}
