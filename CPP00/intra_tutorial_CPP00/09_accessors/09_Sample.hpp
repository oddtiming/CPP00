#pragma once

/** GOAL:
 * 		Understanding how to access private class member
 */

class Sample {

public: 

	Sample( void );
	~Sample( void );

	// These are what we call accessors.
	// Use them as much as is necessary!
	int		getFoo( void ) const;
	void	setFoo( int newFoo );


private:

	int		_foo;

};
