#pragma once

/** GOAL:
 * 		Understanding different c++ comparisons
 */

class Sample {

public: 

	Sample( int foo );
	~Sample( void );

	int		getFoo( void ) const;
	int		compare( Sample * other ) const;

private:

	int		_foo;

};
