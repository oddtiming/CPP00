#include "Zombie.hpp"

/**
 * @brief Allocates a zombie with name `name' and returns its pointer
 * 
 * @return Zombie* needs to be freed
 */
Zombie*	zombieHorde( int N, std::string name ) { 

	if (N <= 0) {
		std::cerr << "zombieHorde() Error : N of zombies needs to be positive" << std::endl;
		return nullptr;
	}

	Zombie*	horde = new Zombie[N];

	for(int i = 0; i < N; i++) {
		horde[i].setName( name );
	}

	return horde;
}
