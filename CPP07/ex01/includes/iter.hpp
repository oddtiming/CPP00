#include <cstddef>

template< class T >
void	iter( T * arr , size_t sz, void (*f)(T &)  ) {

	for ( size_t i = 0; i < sz; i++ ) {
		f( arr[i] );
	}
	return ;
}
