#include "convert.hpp"

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::endl;
using std::string;


void	convertNb( string &str, long double const & ldbl ) { 


	cout << "char\t:";
	try {
		char c = static_cast< char >( ldbl );
		string ctos;					// convert to str to use the ternary
		ctos.append(1, c);
		cout << ( isprint(c) ? "'" + ctos + "'" : "Not Displayable" ) << endl;

	} catch (std::exception e) {
		cout << e.what() << endl; }
	
	
	cout << "int\t:";
	try {
		stoi( str ); // test for overflow separately, to account for scientific notation
		cout << static_cast< int >(ldbl) << endl; 
	} catch (std::out_of_range & e) {
		cout << (ldbl < 0 ? "negative" : "positive") << " overflow" << endl; }
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}


	cout << "float\t:";
	try {
		cout << std::setprecision(str.length()) 
			<< stof( str )
			<< ( ldbl - static_cast< int >( ldbl ) ? "" : ".0" ) << "f" << endl;
		
	} catch (std::out_of_range & e) {
		cout << (ldbl < 0 ? "negative" : "positive") << " overflow" << endl; }
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}


	cout << "double\t:";
	try {
		cout << std::setprecision( (str.length() > 20 ? 20 : str.length() ) 
			<< stod( str )
			<< ( ldbl - static_cast< int >( ldbl ) ? "" : ".0" ) << endl;
		
	} catch (std::out_of_range & e) {
		cout << (ldbl < 0 ? "negative" : "positive") << " overflow" << endl; }
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

}

void	convertNonNb( int const & varType ) { 
	
	cout << "char: " << "impossible" << endl;
	cout << "int: "	<<  "impossible" << endl;
	cout << "float: " << ( varType == T_NAN ? "nan" : "inf" ) << "f" << endl;
	cout << "double: " << ( varType == T_NAN ? "nan" : "inf" ) << endl;
}
