#include <cstddef>
#include <iostream>

template< class T >
void	iter( T * arr , size_t sz, void (*f)(T &)  ) {

	if ( f == nullptr ) {
		std::cerr << "iter() Error: iter fct is nullptr" << std::endl;
		return ;
	}

	for ( size_t i = 0; i < sz; i++ ) {
		f( arr[i] );
	}
	return ;
}

template< class T >
void	iter( T const * arr , size_t sz, void (*f)(T const &)  ) {

	if ( f == nullptr ) {
		std::cerr << "iter() Error: iter fct is nullptr" << std::endl;
		return ;
	}

	for ( size_t i = 0; i < sz; i++ ) {
		f( arr[i] );
	}
	return ;
}
