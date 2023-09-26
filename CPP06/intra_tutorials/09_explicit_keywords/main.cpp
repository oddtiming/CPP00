#include <iostream>

// explicit keyword


class A {};
class B {};

class C {

	public:
 
				 C( A const & var ) { return; }
		explicit C( B const & var ) { return; }
};


void	fct( C const & var ) {

	return ;
}


int	main( ) {

	fct( A() );			// Implicit conversion --> OK
	// fct( B() );		// Will not work, b/c constructor is implicit

	const C a( ( B() ) );

	fct ( a );
	
	return 0;
}
