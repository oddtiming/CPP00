#pragma once

// The goal of this exercise is to assign a const value
class Sample {

public:

	// Here is the problem : we want `pi' to be assigned on initialization
	// This is currently impossible...
	float const	pi;
	int			qd;

	Sample( float const f );
	~Sample( void );


	// Note the `const' at the end of the line. 
	// What does it mean?
	// It signifies to the compiler that the following 
	// member function will never modify the current instance!
	void	bar( void ) const;

};


/** NOTE: Every function that does not modify the attributes
 *  should be declared as const
 * 
 */
