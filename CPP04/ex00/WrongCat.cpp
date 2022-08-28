#include "WrongCat.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

WrongCat::WrongCat( ) : WrongAnimal( "WrongCat" ) {
	std::cout << "WrongCat called" << std::endl;
	return ;
}

WrongCat::WrongCat( WrongCat const & src ) {
	std::cout << "WrongCat copy constructor called" << std::endl;

	*this = src;
}

WrongCat &	WrongCat::operator=( WrongCat const & rhs ) {
	std::cout << "WrongCat assignment operator called" << std::endl;

	this->_type = rhs.getType();
	return *this;
}

WrongCat::~WrongCat( ) {
	std::cout << "~WrongCat called" << std::endl;
}

/*****************************************************************************/
/*                             Member functions                              */
/*****************************************************************************/

void	WrongCat::makeSound( ) const {
	std::cout << "meeeeeeeeeow" << std::endl;
}
