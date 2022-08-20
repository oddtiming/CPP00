#include "Harl.hpp"

void	exit_program( void ) {

	std::cout << "\n\t" << "My dude Harl is izzout! Bye for now!" << "\n" << std::endl;

	exit(EXIT_SUCCESS);
}

bool	ask_yn( std::string prompt ) {

	// Display the prompt
	std::cout << prompt;
	std::cout << " y/n : ";

	// Read the answer
	char	c = 0;
	std::cin >> c;

	// Verify the input
	// If ctrl-D is hit, program stops
	if ( !c ){
		exit_program();
	}
	if (c && c != 'y' && c != 'n') {
		std::cout << "Please enter a y/n answer" << std::endl;
		return ask_yn( prompt );
	}

	return c == 'y' ? true : false;
}

int	ask_int( std::string prompt ) {

	// Display the prompt
	std::cout << prompt;

	// Read the answer
	int	i = 0;
	std::cin >> i;

	return i;
}

int	main( void ) {

	std::string	userInput;
	Harl		harl;

	if ( ask_yn( "Do you want to generate random complaints?" ) ) {
		
		int	nbComplaints = ask_int( "How many do you want? " );
		
		for(int i = 0; i < nbComplaints; i++) {
			harl.complain( harl.levels[ rand() % NB_LEVELS ] );
		}
	}

	do {

		userInput.clear();
		std::cout << "--> What complaint level do you want? DEBUG, INFO, WARNING, ERROR, or RANDOM: ";
		std::getline(std::cin >> std::ws, userInput);
		harl.complain( userInput );
		
	} while (!userInput.empty() && userInput != "EXIT" );
	// Ctrl-D is treated as end of program

	exit_program();

	return 0;
}
