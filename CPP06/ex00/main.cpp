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
using namespace std;

string	strToLower(string str);
int		getVarType(string const & str);
string	getFirstWord(char * const str);


enum e_types {
	T_INT,
	T_FLOAT,
	T_INF,
	T_NAN
};

	
static const string	g_nonNumerInputs[4] = { 
	/* id = 0 */	"INF", 
	/* id = 1 */	"NAN",
	/* id = 2 */	"INFF",
	/* id = 3 */	"NANF" };

class NotAnIntException : public std::exception {
	public :
		virtual const char * what() const throw() {
			return ("Error: input is not a valid number"); }
};

int	main( int argc, char **argv ) {

	if (argc < 2 ) {
		cerr << "Error : input a number to be converted" << endl;
		exit ( EXIT_FAILURE );
	}



	// Lol, this was all for naught, stof(str, &i ) will input the index...
	// Only need to check if the substring from i to end of string t o verify validity

	string	str = strToLower( getFirstWord(argv[1]) );


	size_t	i = 0;
	float	f = static_cast< float >( stof(str, &i) );
	cout << "stof(str, &i) = ";
	cout.precision(4);
	cout << f << endl;
	cout << "str.substr(i).c_str = " << str.substr(i).c_str() << endl;

	if (isnan( f )) {
		cout << "f is nan" << endl; 
	}
	// see e_types for available types
	int	varType = T_INT;

	
	if ( str[i] == '+' || str[i] == '-' )
		i++;
	
	try {

		for ( ; i < str.length(); i++) {
			if ( !isdigit(str[i]) )
				varType = getVarType( &str[i] );
			
			// If nan/nanf/inf/inff, don't check the rest of the string
			if ( varType >=	T_NAN )
				break ;
		}
	}
	catch (NotAnIntException e) {
		cerr << e.what() << endl;
		exit (1);
	}
	catch (std::exception e) {
		cerr << e.what() << endl;
		exit (1);
	}

	cout << "yay !" << endl;


	// convert to char
	// is it displayable?

	// converto to int
	// is it overflowing?

	// convert to float
	// is it overflowing?

	// converto to double
	// is it overflowing?



	return 0;
}


// Returns the var type (from e_type) string belongs to
int		getVarType(string const & str) {
	
	// to check whether a single decimal point is entered
	static bool	isDecimal = false;

	// Handle case of period
	if ( str.at(0) == '.' || str.at(0) == ',' ) {

		if ( isDecimal ) {
			throw NotAnIntException();
		}
		isDecimal = true;	// iff it is the first decimal marker encountered
		return T_FLOAT;
	}

	// Handle case of f
	else if ( str.at(0) == 'f' ) {

		if ( str.length() > 1 ) {			// Check if f is a single last character
			throw NotAnIntException();
		}
		return T_FLOAT;
	}

	// Handle nan/inf/nanf/inff
	for (int i = 0; i < 4; i++) {
		
		if (str == g_nonNumerInputs[i])
			return (i % 2 ?	T_NAN : T_INF);			// Returns NAN for odd, INF for even
	}

	throw NotAnIntException();

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

