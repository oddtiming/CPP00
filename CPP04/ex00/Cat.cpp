#include "Cat.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

Cat::Cat( ) : Animal( "Cat" ) {
	std::cout << "Cat constructor called" << std::endl;
	return ;
}

Cat::Cat( Cat const & src ) {
	std::cout << "Cat copy constructor called" << std::endl;

	*this = src;
}

Cat &	Cat::operator=( Cat const & rhs ) {
	std::cout << "Cat assignment operator called" << std::endl;

	this->_type = rhs.getType();
	return *this;
}

Cat::~Cat( ) {
	std::cout << "~Cat destructor called" << std::endl;
}

/*****************************************************************************/
/*                             Member functions                              */
/*****************************************************************************/

void	Cat::makeSound( ) const {

	// *this uses << overload from Animal parent class
	std::cout << *this << ": \"meowww\"" << std::endl;
}
