#include "Fixed.hpp"
#include <iomanip>

int	main( void ) {

	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const	c( Fixed( 10.5f ) + Fixed( 5.0f ) );
	Fixed const	d( Fixed( 3 ) + Fixed( -1 ) );

	std::cout << "Fixed a;" << std::endl;
	std::cout << "Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );" << std::endl;
	std::cout << "Fixed const c( Fixed( 10.5f ) + Fixed( 5 ) );" << std::endl;
	std::cout << "Fixed const d( Fixed( 3 ) + Fixed( -1 ) );" << std::endl;

	std::cout << "a = " 	<< a	<< std::endl;
	std::cout << "++a = " 	<< ++a	<< std::endl;
	std::cout << "a = " 	<< a	<< std::endl;
	std::cout << "a++ = " 	<< a++	<< std::endl;
	std::cout << "a = " 	<< a	<< std::endl;
	std::cout << "b = " 	<< b	<< std::endl;
	std::cout << "c = " 	<< c	<< std::endl;
	std::cout << "d = " 	<< d	<< std::endl;


	std::cout << "b + c = " << Fixed( b + c ) << std::endl;
	std::cout << "b - c = " << Fixed( b - c ) << std::endl;
	std::cout << "b * c = " << Fixed( b * c ) << std::endl;
	std::cout << "b / c = " << Fixed( b / c ) << std::endl;


	std::cout << "max(b, c) = " << Fixed::max(b, c) << std::endl;
	std::cout << "min(b, c) = " << Fixed::min(b, c) << std::endl;

	Fixed		e = Fixed( 2 );

	std::cout << "\n" << "e = Fixed( 2 );" << std::endl;

	// To output booleans as true/false instead of 1/0
	std::cout << std::boolalpha;
	std::cout << "d == e ? : " << (d == e) << std::endl;
	std::cout << "d == c ? : " << (d == c) << std::endl;
	std::cout << "d != c ? : " << (d != c) << std::endl;
	std::cout << "d > e  ? : " << (d > e) << std::endl;
	std::cout << "d >= e ? : " << (d >= e) << std::endl;
	std::cout << "d <= e ? : " << (d <= e) << std::endl;
	std::cout << "d < e  ? : " << (d < e) << std::endl;
	std::cout << "d < c  ? : " << (d < c) << std::endl;
	std::cout << "d > c  ? : " << (d > c) << std::endl;

	return 0;
}
