#include <iostream>

int	main(void) {
	char	buff[512];


	std::cout << "Hello World!" << std::endl;

	std::cout << "Input a word : ";
	std::cin >> buff;
	
	// Here, a buffer overflow causes UB
	std::cout << "You entered: \"" << buff << "\"" << std::endl;
	
	return 0;
}
