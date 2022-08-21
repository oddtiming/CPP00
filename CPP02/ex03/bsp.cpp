#include "Fixed.hpp"
#include "Point.hpp"

// Uses baryocentric coordinates to determine if 
// the expression of the the baryocentric vectors is positive
// https://mathworld.wolfram.com/PerpDotProduct.html
// https://www.reddit.com/r/learnmath/comments/agfm8g/what_is_perp_dot_product/

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	areaX2 =  a.getX() * ( b.getY() - c.getY() ) 
					+ b.getX() * ( c.getY() - a.getY() )
					+ c.getX() * ( a.getY() - b.getY() ); 
	
	Fixed	u =   a.getY() * c.getX()
				- a.getX() * c.getY()
				+ point.getX() * ( c.getY() - a.getY() )
				+ point.getY() * ( a.getX() - c.getX() );
	
	Fixed	v =   a.getX() * b.getY()
				- a.getY() * b.getX()
				+ point.getX() * ( a.getY() - b.getY() )
				+ point.getY() * ( b.getX() - a.getX() );

	if (areaX2 > 0) {
		return (u > 0) && (v > 0) && (u + v < areaX2 );
	}
	
	return (u < 0) && (v < 0) && ( u + v > areaX2 );
}
