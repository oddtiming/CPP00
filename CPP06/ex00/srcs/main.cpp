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

	if ( argc < 2 || !argv[1][0] ) {
		cerr << "Error : input a number to be converted" << endl;
		exit ( EXIT_FAILURE );
	}
	else if ( argc > 2 || !argv[1][0] ) {
		cerr << "Warning: convert only takes a single argument" << endl;
		exit ( EXIT_FAILURE );
	}

	str = getFirstWord(argv[1]);

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
	// catch (std::out_of_range & e)
	// catch (NotAnIntException e) {
	// 	cerr << e.what() << endl;
	// 	exit (1);
	// }

	varType == T_NB ?
		convertNb( str, ldbl ) :	//true
		convertNonNb( varType );	//false


	return 0;
}
