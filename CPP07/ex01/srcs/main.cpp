#include "iter.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <cstring>
#include <string>

using std::cout;
using std::endl;
using std::string;


template< typename T >
void	decrement( T & x ) {
	x -= 1;
}
template< int > void decrement( int ); // Implemented function template

template< typename T >
void	increment( T & x ) {
	x += 1;
}

void	strToUpper(std::string & str) {
	for ( size_t i = 0; i < str.length(); i++ )
		str[i] = toupper( str[i] );
}

void	strToLower(std::string & str) {
	for ( size_t i = 0; i < str.length(); i++ )
		str[i] = tolower( str[i] );
}

void	flipBool( bool & b ) {
	b = !b;
}

template <typename T>
void	print( T const & i ) {
	cout << i << endl;
}


int main( void ) {

	int		a[3] = { 0, 3, -43 };
	
	cout << "\tint		a[3]" << endl;
	cout << a[0] << endl;
	cout << a[1] << endl;
	cout << a[2] << endl;

	::iter( a, 3, &decrement );
	cout << "\tafter ::iter( a, 3, decrement ):" << endl;

	cout << a[0] << endl;
	cout << a[1] << endl;
	cout << a[2] << endl;

	::iter( a, 3, &increment );
	cout << "\tafter ::iter( a, 3, increment ):" << endl;

	cout << a[0] << endl;
	cout << a[1] << endl;
	cout << a[2] << endl;

	float		f[3] = { 2.4447f, 3.7f, -43.7323f };
	
	cout << "\tfloat	f[3]" << endl;
	cout << f[0] << endl;
	cout << f[1] << endl;
	cout << f[2] << endl;

	::iter( f, 3, &decrement );
	cout << "\tafter ::iter( f, 3, decrement ):" << endl;
	cout << f[0] << endl;
	cout << f[1] << endl;
	cout << f[2] << endl;

	::iter( f, 3, &increment );
	cout << "\tafter ::iter( f, 3, increment ):" << endl;

	cout << f[0] << endl;
	cout << f[1] << endl;
	cout << f[2] << endl;
	
	bool	b[3] = { true, false, true };
	
	cout << "\tbool	b[3]" << endl;
	cout << std::boolalpha;
	cout << b[0] << endl;
	cout << b[1] << endl;
	cout << b[2] << endl;

	::iter( b, 3, flipBool );

	cout << "\tafter ::iter( f, 3, flipBool ):" << endl;
	cout << b[0] << endl;
	cout << b[1] << endl;
	cout << b[2] << endl;

	string	s[3] = {
		"this is a lowercase string",
		"THIS IS AN UPPERCASE STRING",
		"ThiS Is a MixED StRinG"
	};

	cout << "\tstring	s[3]" << endl;
	cout << s[0] << endl;
	cout << s[1] << endl;
	cout << s[2] << endl;

	::iter( s, 3, strToUpper );
	cout << "\tafter ::iter( s, 3, strToUpper ):" << endl;

	cout << s[0] << endl;
	cout << s[1] << endl;
	cout << s[2] << endl;

	::iter( s, 3, strToLower );
	cout << "\tafter ::iter( s, 3, strToLower ):" << endl;

	cout << s[0] << endl;
	cout << s[1] << endl;
	cout << s[2] << endl;



	Fixed	* fix = new Fixed[3];
	::iter( fix, 3, print );

	delete [] fix;

	return 0;
}
