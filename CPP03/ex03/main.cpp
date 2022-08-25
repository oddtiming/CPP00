#include "DiamondTrap.hpp"
#include <iostream>
#include <cstdlib>
#include <thread>		// std::this_thread::sleep_for
#include <chrono>		 // std::chrono::seconds

void	takeDamage( DiamondTrap & diamondTrap ) {
	diamondTrap.FragTrap::takeDamage( rand() % ( FRAG_HP / 2 ) );
}

void	beRepaired( DiamondTrap & diamondTrap ) {
	diamondTrap.FragTrap::beRepaired( rand() % ( FRAG_HP / 4 ) );
}

void	attack( DiamondTrap & diamondTrap ) {

	std::string	target( "Johnny ARRRRGGGHHHHH" );
	
	diamondTrap.attack( target );
}


void	whoAmI( DiamondTrap & diamondTrap ) {
	diamondTrap.whoAmI();
}

void	highFivesGuys( DiamondTrap & diamondTrap ) {
	diamondTrap.highFivesGuys();
}

int	main( ) {

	DiamondTrap	diamondTrap( "Diamond_is_unbreakable" );
	// DiamondTrap	unnamedDiamondTrap;

	
	whoAmI( diamondTrap );
	std::this_thread::sleep_for (std::chrono::seconds( 1 ));

	std::string	target( "Johnny ARRRRGGGHHHHH" );
	std::cout << "\n" << "Target is: \"" << target << "\"\n" << std::endl;
	std::this_thread::sleep_for (std::chrono::seconds( 1 ));

	void ( *doActions[5])( DiamondTrap& ) = {
		&attack,
		&beRepaired,
		&takeDamage,
		&whoAmI,
		&highFivesGuys
	};


	for ( int i = 0; i < 5; i++ ) {

		doActions[ rand() % 5 ](diamondTrap);
		std::this_thread::sleep_for (std::chrono::milliseconds( 300 ));
	}

	diamondTrap.guardGate();
	std::this_thread::sleep_for (std::chrono::seconds( 2 ));

	for ( int i = 0; i < 10; i++ ) {

		doActions[ rand() % 5 ](diamondTrap);
		std::this_thread::sleep_for (std::chrono::milliseconds( 300 ));
	}

	return 0;
}
