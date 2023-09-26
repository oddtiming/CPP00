#include "Sample.hpp"

int	main( void ) {

	Sample sample;

	sample.bar( 'a' );
	sample.bar( 42 );
	sample.bar( 3.14f );
	sample.bar( sample );

	return 0;
}
