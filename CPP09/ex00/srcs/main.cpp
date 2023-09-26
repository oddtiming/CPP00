#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using std::string;
using std::map;

// string should be changed to datetime

map<string, float> parseDatabase() {
	// Read the input file with an ifstream

	// Feed line by line into the map
		// On error, exit gracefully with proper error message
	map<string, float> parsedDb = map<string, float>();		
	
	return parsedDb;
}

void print_usage(char *executableName) {
	std::cerr << "Error. Usage: " << executableName << " [path_to_input_file]\n\n"
			  << "Input format:\n"
			  << "      Date | Value \n"
			  << "YYYY-MM-DD | [0-1000]\n" << std::endl;
}

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		print_usage(argv[0]);
		exit(EXIT_FAILURE);
	}

	// Parse the DB into a map
	map<string, float> db = parseDatabase();

	// Parse input line by line
		// Pass the line and reference to the map to a method that outputs to stdout/stderr

	return 0;
}

