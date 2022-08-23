#include "Cat.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

Cat::Cat( ) : Animal( "Cat" ) {
	std::cout << "Cat called" << std::endl;
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
	std::cout << "~Cat called" << std::endl;
}

/*****************************************************************************/
/*                             Member functions                              */
/*****************************************************************************/

void	Cat::makeSound( ) const {
	std::cout << this->_type << ": \"meowww\"" << std::endl;
}

std::string	Cat::getType( ) const {
	return this->_type;
}


/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/


std::ostream &	operator<<( std::ostream & o, Cat const & rhs ) {

	o << rhs.getType();
	return o;
}
