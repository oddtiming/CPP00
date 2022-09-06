#include "convert.hpp"

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// Returns the var type (from e_type) string belongs to
int		getVarType( string const & str, size_t const & i, long double const & ldbl ) {
	
	/**
	 * NOTE: need to also convet char litterals
	 * 
	 */

	// Check if more than a single char is left in the string
	if ( ( str.length() > i + 1) 
		|| ( str.length() == i + 1 && str.length() > 1 && str.at(i) != 'f' ) ) {

		throw NotAnIntException();
	}

	if ( isnan( ldbl ) )
		return T_NAN;
	else if ( isinf( ldbl ) )
		return T_INF;


	return T_NB;

}

string	getWord(char * const str) {

	stringstream	ss(str);
	string			firstWord;
	
	ss >> std::ws >> firstWord;

	return firstWord;
}
