#include <iostream>


/**
 * 		A reference can be described as an alias to a variable.
 * 
 * 		Can also be seen as a  pointer that is always
 * 	dereferenced and that is never null.
 */
int		main( void ) {

	int		nbOfBalls = 42;
	int		*ballsPtr = &nbOfBalls;
	int		&ballsRef = nbOfBalls;
	//int	&ballsRef2; -> would give us an error, a reference has to be initialized
	// A reference comes with the assurance that it is non-null and not garbage values


	std::cout << "nb of balls = " << nbOfBalls 
		<< " = " << ballsRef
		<< " = " << *ballsPtr 
		<< std::endl;

	*ballsPtr = 21;
	std::cout << "after `*ballsPtr = 21\': " << nbOfBalls 
		<< " = " << ballsRef
		<< " = " << *ballsPtr
		<< std::endl;

	ballsRef = 84;
	std::cout << "after `ballsRef = 84;\': " << nbOfBalls 
		<< " = " << ballsRef
		<< " = " << *ballsPtr
		<< std::endl;

	return 0;
}
