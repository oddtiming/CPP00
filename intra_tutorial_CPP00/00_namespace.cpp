#include <stdio.h>

int gl_var = 1;
int fct( void ) { return 2; }

namespace	Foo {

	int gl_var = 3;
	int fct( void ) { return 4; }

}

namespace	Bar {
	
	int gl_var = 5;
	int fct( void ) { return 6; }

}

namespace	Moo = Foo;

int	main(void) {

	printf("gl_var		=	[%d]\n", gl_var);		// 1
	printf("fct()		=	[%d]\n", fct());		// 2
	
	printf("Foo::gl_var	=	[%d]\n", Foo::gl_var);	// 3
	printf("Foo::fct()	=	[%d]\n", Foo::fct());	// 4
	
	printf("Bar::gl_var	=	[%d]\n", Bar::gl_var);	// 5
	printf("Bar::fct()	=	[%d]\n", Bar::fct());	// 6
	
	printf("Moo::gl_var	=	[%d]\n", Moo::gl_var);	// 3
	printf("Moo::fct()	=	[%d]\n", Moo::fct());	// 4
	
	// Empty namespace is equivalent to no namespace.
	// Sometimes used for clarity.
	printf("::gl_var	=	[%d]\n", ::gl_var);		// 1
	printf("::fct()		=	[%d]\n", ::fct());		// 2
	
	return 0;
}
