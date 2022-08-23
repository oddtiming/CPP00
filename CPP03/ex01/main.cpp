#include "ScavTrap.hpp"
#include <iostream>
#include <cstdlib>
#include <thread>		// std::this_thread::sleep_for
#include <chrono>		 // std::chrono::seconds

int	main( ) {

	ScavTrap	scavTrap( "Scavie" );
	ScavTrap	unnamedScavTrap;

	std::string	target( "A powerful foe" );


	std::cout << "\n" << "Target is: \"" << target << "\"\n" << std::endl;


	for ( int i = 0; i < 4; i += 2 ) {

		scavTrap.attack( target );

		std::this_thread::sleep_for (std::chrono::milliseconds( 300 ));
		
		scavTrap.takeDamage( rand() % SCAV_HP / 2 );

		std::this_thread::sleep_for (std::chrono::milliseconds( 300 ));
	}
	
	scavTrap.guardGate();
	std::this_thread::sleep_for (std::chrono::seconds( 2 ));

	while ( scavTrap.getEP() ) {

		scavTrap.attack( target );
		scavTrap.attack( target );
		scavTrap.attack( target );

		std::this_thread::sleep_for (std::chrono::milliseconds( 300 ));
		
		scavTrap.takeDamage( rand() % SCAV_HP / 2 );
		scavTrap.takeDamage( rand() % SCAV_HP / 2 );

		std::this_thread::sleep_for (std::chrono::milliseconds( 300 ));
	}

	if ( scavTrap.getHP() )
		scavTrap.takeDamage( SCAV_HP );
		
	scavTrap.takeDamage( 0 );
	scavTrap.beRepaired( 100 );
	
	return 0;
}
