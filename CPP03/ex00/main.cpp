#include <iostream>
#include "ClapTrap.hpp"

int	main( ) {

	ClapTrap	clapTrap1( "Clappy" );
	ClapTrap	clapTrap2( "Trapper" );

	std::string	target( "The wind or some shit, doesn't matter" );


	std::cout << "\n" << "Target is: \"" << target << "\"\n" << std::endl;

	clapTrap1.attack( target );
	clapTrap1.takeDamage( 2 );
	clapTrap1.takeDamage( 5 );
	clapTrap1.takeDamage( 10 );
	clapTrap1.takeDamage( 10 );

	
	
	clapTrap1.beRepaired( 100 );
	clapTrap1.takeDamage( 101 );

	

	return 0;
}
