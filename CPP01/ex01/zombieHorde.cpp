#include "Zombie.hpp"

/**
 * @brief Allocates a zombie with name `name' and returns its pointer
 * 
 * @return Zombie* needs to be freed
 */
Zombie*	zombieHorde( int N, std::string name ) { 

	Zombie*	horde = new Zombie[N];

	for(int i = 0; i < N; i++) {
		horde[i].setName( name );
	}

	return horde;
}
