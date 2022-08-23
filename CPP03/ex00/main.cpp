#include "ClapTrap.hpp"
#include <iostream>
#include <cstdlib>
#include <thread>		// std::this_thread::sleep_for
#include <chrono>		 // std::chrono::seconds

int	main( ) {

	ClapTrap	clapTrap1( "Clappy" );
	ClapTrap	clapTrap2;

	std::string	target( "The wind or some shit, doesn't matter" );


	std::cout << "\n" << "Target is: \"" << target << "\"\n" << std::endl;

	clapTrap1.takeDamage( rand() % CLAP_HP / 2 );

	for ( int i = 0; i < CLAP_EP / 2; i += 2 ) {

		clapTrap1.attack( target );

		std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
		
		clapTrap1.takeDamage( rand() % CLAP_HP / 2 );

		std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
	}

	if ( clapTrap1.getHP() )
		clapTrap1.takeDamage( CLAP_HP );
		
	clapTrap1.takeDamage( 1 );
	clapTrap1.beRepaired( 100 );

	while ( clapTrap1.getEP() ) {

		clapTrap1.attack( target );

		std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
		
		clapTrap1.takeDamage( rand() % CLAP_HP / 2 );

		std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
	}

	for (int i = 0; i < 3; i++) {

		clapTrap1.beRepaired( 0 );

		std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
	}
	
	return 0;
}
