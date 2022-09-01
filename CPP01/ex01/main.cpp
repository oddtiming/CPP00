#include <iostream>		// std::cout, std::endl
#include <thread>		// std::this_thread::sleep_for
#include <chrono>		 // std::chrono::seconds
#include "Zombie.hpp"

int	main( void ) {

	std::string	name("zombiePartyPerson");
	int			N = 12;
	Zombie		*horde = zombieHorde( N, "zombiePartyPerson" );

	if (horde == nullptr) {
		exit(EXIT_FAILURE);
	}


	std::cout << "\n\tOkay, did we get all " << N << " " << name << "s?" << "\n\n";
	std::this_thread::sleep_for (std::chrono::seconds(1));

	for(int i = 0; i < N; i++) {
		horde[i].announce();
		std::this_thread::sleep_for (std::chrono::milliseconds(30));
	}
	std::this_thread::sleep_for (std::chrono::milliseconds(400));

	std::cout << "\n\tAlriiiight, now that's what I call a horde!" << "\n";

	std::this_thread::sleep_for (std::chrono::seconds(1));
	std::cout << "\n\t  ..." << "\n";
	std::this_thread::sleep_for (std::chrono::seconds(1));
	std::cout << "\n\t  ..." << "\n";
	std::this_thread::sleep_for (std::chrono::seconds(1));
	std::cout << "\n\t  ..." << "\n";

	std::cout << "\n\t Okay bye bye now!\n" << std::endl;
	std::this_thread::sleep_for (std::chrono::milliseconds(500));

	delete [] horde;

	return 0;
}
