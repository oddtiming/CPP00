#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;

string	strToLower(string str);
bool	validateString(string const & str, bool & isFloat);
string	getFirstWord(char * const str);

class NotAnIntException : public std::exception {
	public :
		virtual const char * what() const throw() {
			return ("Error: input is not a valid number"); }
};

int	main( int argc, char **argv ) {

	if (argc < 2 ) {
		cerr << "Error : input a number to be converted" << endl;
	}

	char const * const	nonNumerInputs[4] = { 
		"inf", "nan", "inff", "nanf" };

	string	str = strToLower( getFirstWord(argv[1]) );

	size_t	i = 0;
	bool	isFloat = false;

	if ( str[i] == '+' || str[i] == '-' )
		i++;
	
	try {
		for ( ; i < str.length(); i++) {
			if ( !isdigit(str[i]) && !validateString(str) ) {
				isFloat = (str[i] == 'f' ? true : false);
			}
		}
	} catch (NotAnIntException e) {
		cerr << e.what() << endl; }



	return 0;
}

bool	validateString(string const & str, bool & isFloat) {

	// Handle case of period 

	// Handle case of f

	// Handle nan/inf/nanf/inff


}

string	getFirstWord(char * const str) {

	stringstream ss(str);
	string	firstWord;
	
	ss >> std::ws >> firstWord;

	return firstWord;
}

string	strToLower(string str) {

	string	toLower;
	size_t	i = 0;
	
	while ( i < str.length() ) {
		toLower += tolower(str[i++]);
	}

	return toLower;
}

