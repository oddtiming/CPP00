#include <iostream>
#include "12_Sample.hpp"

int	main( void ) {
	Sample	instance;
	Sample *instancePtr = &instance;

	// That's weird as fuck, but it makes sense insofar as you
	// understand that `ptr' and `fct' do nothing by themselves!
	int		Sample::*ptr = NULL;

	// Here, `fct' absolutely needs the const qualifier, or else will not compile
	void	(Sample::*fct)(void) const;

	/**
	 *  Here you assign variable foo's address to ptr.
	 * 	If class Sample had more int member attributes, you could assign any to `ptr'
	 * 
	 * NOTE: `ptr' does nothing by itself! It needs to be assigned to an 
	 * 			instance in order to make sense.
	 * 
	 * NOTE: in the same way, only a pointer can be declared in such a way.
	 * 
	 */
	ptr = &Sample::foo;

	std::cout << "Value of member foo at first: " << instance.foo<< std::endl;
	
	// Here, `.*ptr' dereferences this specific instance of class Sample
	instance.*ptr = 21;
	std::cout << "Value of member foo after instance.*ptr = 21: " << instance.foo<< std::endl;


	instancePtr->*ptr = 42;
	std::cout << "Value of member foo after instancePtr->*ptr = 42: " << instance.foo<< std::endl;

	// Note tat there is sadly no way to know that `Sample::bar' is a function
	fct = &Sample::bar;

	(instance.*fct)();
	(instancePtr->*fct)();

	return 0;
}
