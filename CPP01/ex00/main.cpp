#include <iostream>
#include "Zombie.hpp"

int	main( void ) {

	Zombie* peterPtr = newZombie( "Peter the pointer" );

	std::cout << "Zombie " << peterPtr->getName() << " has been allocated on the heap, it needs to be deleted" << std::endl;

	peterPtr->announce();

	std::cout << "I know, " << peterPtr->getName() 
		<< ", I know.. But at least you have it better than Mr minute man over there" << std::endl;

	randomChump( "minuteMan" );

	peterPtr->announce();
	std::cout << "Sorry " << peterPtr->getName() << ", I don't make the rules :/" << std::endl;

	delete peterPtr;
	
	return 0;
}
