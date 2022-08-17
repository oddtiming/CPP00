#pragma once

/** GOAL:
 * 		Non-member attributes/functions are also called class attributes/functions
 * 		Member atts/fs == instance atts/fs
 * 
 * 		The difference is that member fcts can only be called by instances of a class
 * 		This means that non-member atts/fs can be accessed by non-instances.
 * 
 */

class Sample {

public: 

	Sample( void );
	~Sample( void );

	static int		getNbInstances( void );


private:

	// Here, the total nb of instances is smth that supercedes single instances
	static int		_nbInstances;

};
