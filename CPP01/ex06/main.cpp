#include "Harl.hpp"

int	main( int argc, char** argv ) {

	Harl		harl;

	if (argc != 2) {
		std::cerr << "Error.\n Usage: " << argv[0] << " 'DEBUG/INFO/WARNING/ERROR'" << std::endl;
		exit(EXIT_FAILURE);
	}

	harl.complain( argv[1] );

	return 0;
}
