#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( ) {

	Bureaucrat topBob( "topBob", 1 );
	Bureaucrat middleBob( "middleBob", 42 );
	Bureaucrat lowerBob( "lowerBob", 150 );


	Form topForm( "acquisition request", 1, 50 );
	Form middleForm( "timeoff request", 3, 42 );
	Form lowerForm( "address change request", 75, 150 );


	// What is the best try/catch aesthetic? 
	// The compact
	try {
		// Grade too high
		Bureaucrat wrongBob( "wrongBob", 0); 
	} catch (std::exception & e) { std::cerr << "\n" << e.what() << std::endl;	}

	// The efficient
	try {
		// Grade too low
		Form wrongForm( "wrongForm", 1, 152 );
 	} catch (std::exception & e) {
		std::cerr << "\n" << e.what() << std::endl;
 	}


	// The old school
	try
	{
		// Signed twice
		topBob.signForm( topForm );
		topBob.signForm( topForm );
	}
	catch (std::exception & e)
	{
		std::cerr << "\n" << e.what() << std::endl;
 	}
	

	topBob.demote( );

	// The misaligned
	// Wrong permission to sign
	try { lowerBob.signForm( topForm ); }
	catch (std::exception & e) { std::cerr << "\n" << e.what() << std::endl; }

	middleBob.executeForm( topForm );

	// Unsigned form
	try { topBob.executeForm( middleForm ); }
	catch (std::exception & e) { std::cerr << "\n" << e.what() << std::endl; }

	
	topBob.signForm( middleForm );
	middleBob.executeForm( middleForm );
	
	middleBob.demote( );

	// Wrong permission to execute
	try { middleBob.executeForm( middleForm ); }
	catch (std::exception & e) { std::cerr << "\n" << e.what() << std::endl; }
	 

	return 0;
}
