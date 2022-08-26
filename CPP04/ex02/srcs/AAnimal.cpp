#include "AAnimal.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

AAnimal::AAnimal( ) : _type( "AAnimal" ) {
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal( std::string type ) : _type( type ) {
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal( AAnimal const & src ) {
	std::cout << "AAnimal copy constructor called" << std::endl;

	*this = src;
}

AAnimal &	AAnimal::operator=( AAnimal const & rhs ) {
	this->_type = rhs.getType();
	return *this;
}

AAnimal::~AAnimal( ) {
	std::cout << "~AAnimal called" << std::endl;
}

/*****************************************************************************/
/*                             Getters/Setters                               */
/*****************************************************************************/

std::string const &		AAnimal::getType( ) const {
	return this->_type;
}


/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/


std::ostream &	operator<<( std::ostream & o, AAnimal const & rhs ) {

	o << rhs.getType();
	return o;
}
