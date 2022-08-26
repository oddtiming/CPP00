#include "Dog.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

Dog::Dog( ) : Animal( "Dog" ) {
	std::cout << "Dog constructor called" << std::endl;
	return ;
}

Dog::Dog( Dog const & src ) {
	std::cout << "Dog copy constructor called" << std::endl;

	*this = src;
}

Dog &	Dog::operator=( Dog const & rhs ) {
	std::cout << "Dog assignment operator called" << std::endl;

	this->_type = rhs.getType();
	return *this;
}

Dog::~Dog( ) {
	std::cout << "~Dog called" << std::endl;
}

/*****************************************************************************/
/*                             Member functions                              */
/*****************************************************************************/

void	Dog::makeSound( ) const {

	// *this uses << overload from Animal parent class
	std::cout << *this << ": \"Woof! Woof!\"" << std::endl;
}
