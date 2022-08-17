#include <iostream>
#include <string>

std::string	strToUpper(std::string str) {

	for (size_t i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}
	
	return str;
}

int	main(int argc, char **argv) {

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}

	for (int i = 1; i < argc; i++) {
		std::cout << strToUpper(argv[i]);
	}

	std::cout << std::endl;
	return 0;
}