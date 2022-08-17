#include <iostream>
#include "06_Sample.hpp"

/**	init_list style initialization
 *	This will allow us to declare const !
 *
 * @note we are not assigning value f to `pi', but rather 
 * 		initializing `pi' attribute at value `f'
 */
Sample::Sample( float const f ) : pi( f ), qd( 42 ) {
	
	std::cout << "Const constructor called" << "\n";


	return ;
}

Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

// `const' there means that the following function will never
// change any attributes of the calling class instance
void	Sample::bar( void ) const {

	std::cout << "this->pi = " << this->pi << "\n";
	std::cout << "this->qd = " << this->qd << std::endl;

// Even though it is not a const member attribute, trying
// the following line will throw an error
	// this->qd = 1;

	return ;
}
