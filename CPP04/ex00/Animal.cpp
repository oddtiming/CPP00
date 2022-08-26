#include "Animal.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

Animal::Animal( ) : _type( "Animal" ) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( std::string type ) : _type( type ) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( Animal const & src ) {
	std::cout << "Animal copy constructor called" << std::endl;

	*this = src;
}

Animal &	Animal::operator=( Animal const & rhs ) {
	this->_type = rhs.getType();
	return *this;
}

Animal::~Animal( ) {
	std::cout << "~Animal called" << std::endl;
}

/*****************************************************************************/
/*                             Getters/Setters                               */
/*****************************************************************************/

void	Animal::makeSound( ) const {
	std::cout << this->_type << ": \"I'm an animal, yo\"" << std::endl;
}

std::string	const &	Animal::getType( ) const {
	return this->_type;
}


/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/


std::ostream &	operator<<( std::ostream & o, Animal const & rhs ) {

	o << rhs.getType();
	return o;
}
