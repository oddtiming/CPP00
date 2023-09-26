#include "FragTrap.hpp"
#include <iostream>
#include <cstdlib>
#include <thread>		// std::this_thread::sleep_for
#include <chrono>		 // std::chrono::seconds


#define NB_ACTIONS 4

void	takeDamage( FragTrap & fragTrap ) {
	fragTrap.takeDamage( rand() % ( FRAG_HP / 2 ) );
}

void	beRepaired( FragTrap & fragTrap ) {
	fragTrap.beRepaired( rand() % ( FRAG_HP / 4 ) );
}

void	highFivesGuys( FragTrap & fragTrap ) {
	fragTrap.highFivesGuys( );
}

void	attack( FragTrap & fragTrap ) {

	std::string	target( "Buddy McBaddy" );
	
	fragTrap.attack( target );
}


int	main( ) {

	FragTrap	fragTrap( "Fraggy" );
	FragTrap	unnamedFragTrap;

	std::string	target( "Buddy McBaddy" );
	std::cout << "\n" << "Target is: \"" << target << "\"\n" << std::endl;


	void ( *doActions[ NB_ACTIONS ])( FragTrap& ) = {
		&attack,
		&beRepaired,
		&takeDamage,
		&highFivesGuys
	};

	while ( fragTrap.getEP() ) {

		doActions[ rand() %  NB_ACTIONS  ](fragTrap);
		std::this_thread::sleep_for (std::chrono::milliseconds( 300 ));
	}
	doActions[ rand() %  NB_ACTIONS  ](fragTrap);
	doActions[ rand() %  NB_ACTIONS  ](fragTrap);
	
	return 0;
}
