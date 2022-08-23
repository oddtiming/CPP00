#include "Dog.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

Dog::Dog( ) : AAnimal( "Dog" ), _brain( new Brain() ) {
	std::cout << "Dog constructor called" << std::endl;
	return ;
}

Dog::Dog( Dog const & src ) : _brain( new Brain() ) {
	std::cout << "Dog copy constructor called" << std::endl;

	*this = src;
}

Dog &	Dog::operator=( Dog const & rhs ) {
	std::cout << "Dog assignment operator called" << std::endl;

	this->_type = rhs.getType();
	return *this;
}

Dog::~Dog( ) {
	delete	_brain;
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

void		Dog::spewIdea( ) const {
	static	uint index = 50;

	std::cout << getType() << " has an idea for a new dog band name : " 
		<< _brain->getIdea( index ) << std::endl;
	
	index++;
	index %= 100;
	return ;
}


/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/


std::ostream &	operator<<( std::ostream & o, Dog const & rhs ) {

	o << rhs.getType();
	return o;
}
