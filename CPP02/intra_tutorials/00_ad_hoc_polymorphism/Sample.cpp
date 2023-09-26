#include "Sample.hpp"

Sample::Sample( void ) {
 return ;
}

Sample::~Sample( void ) {
 return ;
}

void	Sample::bar( char const c ) const {

	std::cout << "Member function bar called with char overload = " << c << std::endl;
	return ;
}

void	Sample::bar( int const c ) const {

	std::cout << "Member function bar called with int overload = " << c << std::endl;
	return ;
}

void	Sample::bar( float const c ) const {

	std::cout << "Member function bar called with float overload = " << c << std::endl;
	return ;
}

void	Sample::bar( Sample const c ) const {

	std::cout << "Member function bar called with param const overload " << &c << std::endl;
	return ;
}
