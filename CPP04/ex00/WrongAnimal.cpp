#include "WrongAnimal.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

WrongAnimal::WrongAnimal( ) : _type( "WrongAnimal" ) {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type( type ) {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src ) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;

	*this = src;
}

WrongAnimal &	WrongAnimal::operator=( WrongAnimal const & rhs ) {
	this->_type = rhs.getType();
	return *this;
}

WrongAnimal::~WrongAnimal( ) {
	std::cout << "~WrongAnimal called" << std::endl;
}

/*****************************************************************************/
/*                             Getters/Setters                               */
/*****************************************************************************/

void	WrongAnimal::makeSound( ) const {
	std::cout << this->_type << ": \"I'm a WrongAnimal, yo\"" << std::endl;
}

std::string	const &		WrongAnimal::getType( ) const {
	return this->_type;
}


/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/

std::ostream &	operator<<( std::ostream & o, WrongAnimal const & rhs ) {

	o << rhs.getType();
	return o;
}
