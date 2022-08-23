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
	std::cout << this->_type << ": \"Woof! Woof!\"" << std::endl;
}

std::string		Dog::getType( ) const {
	return this->_type;
}


/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/


std::ostream &	operator<<( std::ostream & o, Dog const & rhs ) {

	o << rhs.getType();
	return o;
}
