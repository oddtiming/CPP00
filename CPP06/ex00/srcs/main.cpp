#include "convert.hpp"

#include <iostream>
#include <string>
#include <limits>

using std::cout;
using std::cerr;
using std::endl;
using std::string;


int	main( int argc, char **argv )
{
	string		str;			// converted argv[1]
	size_t		i = 0;			// will store pos in string of first non-digit char
	int			varType = 0;	// see e_types for available types
	long double	ldbl = 0;

	// Protect for no/empty argument
	if ( argc < 2 || !argv[1][0] ) {
		cerr << "Error : input a number to be converted" << endl;
		exit ( EXIT_FAILURE );
	}
	// Issue a warning if more than one arg is passed
	if ( argc > 2 ) {
		cerr << "Warning: only converts the first argument" << endl;
	}

	// To account for char literals
	if (!argv[1][1]) {
		ldbl = static_cast< double >( argv[1][0] );
		str = std::to_string(ldbl);
	}
	else {
		str = getWord(argv[1]);
		if ( getWord(&argv[1][str.length()]).empty() == false ) {
			cerr << "Warning: only converts the first argument" << endl;
		}
	}


	try {
		ldbl = stold( str, &i );
		varType = getVarType( str, i, ldbl);
	}
	catch (std::exception & e) {
		cerr << e.what() << ": Please enter a number between " 
			<< std::numeric_limits< long double >::min() << " and "
			<< std::numeric_limits< long double >::max() << endl;
		exit (1);
	}


	varType == T_NB ?
		convertNb( str, ldbl ) :	//true
		convertNonNb( varType );	//false


	return 0;
}
