#include "Fixed.hpp"
#include "Point.hpp"
#include <iomanip>

/*******************************************************/
/*                                                     */
/*	           To visualize the triangles              */
/*                                                     */
/*	       https://www.geogebra.org/m/Adc44ZZq         */
/*                                                     */
/******************************************************/

bool 	bsp( Point const a, Point const b, Point const c, Point const point);
void	_generateTest( Point const p, Point const & a, Point const & b, Point const & c );

int	main( void ) {

	// First triangle
	Point	a( -2, 3 );
	Point	b( -3, -1 );
	Point	c( 3, -2 );

	std::cout << "\n\t*** First triangle is " << a << b << c << " ***\n" << std::endl;
	std::cout << "Point" << "\t\t" << "|" << std::setw(8) << " in triangle?\n" << std::endl;

	_generateTest( Point( 0, 0 ) , a, b, c );
	_generateTest( Point( -2, 3 ) , a, b, c );
	_generateTest( Point( -3, -1 ) , a, b, c );
	_generateTest( Point( 3, -2 ) , a, b, c );
	_generateTest( Point( -1, 1 ) , a, b, c );
	_generateTest( Point( 10, 1 ) , a, b, c );
	_generateTest( Point( -2, 1 ) , a, b, c );
	_generateTest( Point( -2, 0 ) , a, b, c );
	_generateTest( Point( 2, 0 ) , a, b, c );

	// Second triangle
	Point	d( 1, 0 );
	Point	e( 4, 4 );
	Point	f( 0, 5 );

	std::cout << "\n\n\t*** Second triangle is " << d << e << f << " ***\n" << std::endl;
	std::cout << "Point" << "\t\t" << "|" << std::setw(8) << " in triangle?\n" << std::endl;
	
	_generateTest( Point( 1, 0 ), d, e, f );
	_generateTest( Point( 0, 5 ), d, e, f );
	_generateTest( Point( 4, 4 ), d, e, f );
	_generateTest( Point( 0, 4 ), d, e, f );
	_generateTest( Point( 1, 3 ), d, e, f );
	_generateTest( Point( 2, 4 ), d, e, f );
	_generateTest( Point( 2, 2 ), d, e, f );
	_generateTest( Point( 15, -1 ), d, e, f );

	return 0;
}

void	_generateTest( Point const p, Point const & a, Point const & b, Point const & c ) {

	std::cout << p;
	std::cout.clear();
	std::cout << "\t: ";
	std::cout << std::boolalpha;
	std::cout << bsp(	Point( a.getX(), a.getY() ),
						Point( b.getX(), b.getY() ),
						Point( c.getX(), c.getY() ),
						Point( p.getX(), p.getY() ) ) << std::endl;
}
