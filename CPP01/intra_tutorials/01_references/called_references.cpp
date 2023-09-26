#include <iostream>
#include <string>

void	byPtr( std::string *str ) {
	*str += " and pointers";
}

void	byConstPtr( std::string const *str ) {

	std::cout << "in byConstPtr(), *str = " << *str << std::endl;
}

void	byRef( std::string &str ) {
	str += " and references";
}

void	byConstRef( std::string const &str ) {

	std::cout << "in byConstRef(), str = " << str << std::endl;
}

int		main( void ) {

	std::string	str = "I love variables";


	std::cout << str << std::endl;

	byPtr( &str );
	std::cout << "after byPtr(): "<< str << std::endl;
	
	byConstPtr( &str );

	byRef( str );
	std::cout << "after byRef(): "<< str << std::endl;

	byConstRef( str );

	return 0;
}
