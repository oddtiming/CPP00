#include <iostream>		// std::cout, std::endl, ios::rdbuf()
#include <fstream>		// std::ifstream
#include <sstream>		// std::ostringstream, std::endl
#include <string>		// find(), substr(), length()

std::string	strReplace( std::string str, std::string toReplace, std::string replacement  ) {
	std::ostringstream	oss;
	size_t			pos = 0;
	size_t			posToReplace = str.find(toReplace, pos);

	// Protection for empty args
	if (replacement.empty() || toReplace.empty())
		return str;

	while ( posToReplace != str.npos ) {
		oss << str.substr(pos, posToReplace - pos);
		oss << replacement;
		pos = posToReplace + toReplace.length();
		posToReplace = str.find(toReplace, pos);
	}
	oss << str.substr(pos, str.length() - pos);

	return oss.str();
}

std::string	fileToStr( std::string fileName ) {
	std::ifstream		ifs( fileName );
	std::ostringstream	oss;


    if (!ifs.is_open()) {
		std::cerr << "Could not open file '" << fileName << "'" << std::endl;
		exit(EXIT_FAILURE);
    }

	oss << ifs.rdbuf();
	ifs.close();

	return oss.str();
}

int	main( int argc, char **argv ) {

	if (argc != 4) {
		std::cerr << "Error." << "\n" << "Usage: " 
			<< argv[0] << " `filename\' `strToReplace\' `strReplacement\'" << std::endl;
		exit( EXIT_FAILURE );
	}


	std::string		fileName( argv[1] );
	std::string		original = fileToStr( fileName );
	std::string		replaced = strReplace( original, argv[2], argv[3] );

	if (original == replaced) {
		std::cerr << "Error: string to replace : '"		<< argv[2]	<< "'\n"
				  << "was not found in string  : "	<< original	<< std::endl;
		return 1;
	}

	std::cout << "original string		: '"	<< original	<< "'\n"
			  << "string to replace	: '"		<< argv[2]	<< "'\n"
			  << "replacement		: '"		<< argv[3]	<< "'\n"
			  << "replaced string		: '"	<< replaced	<< "'\n";

	std::ofstream	ofs( fileName.append( ".replace" ) );
	ofs << replaced;
	ofs.close();

	return 0;
}
