#include "Cat.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

Cat::Cat( ) : Animal( "Cat" ), _brain( new Brain() ) {
	std::cout << "Cat called" << std::endl;
	return ;
}

Cat::Cat( Cat const & src ) : _brain( new Brain(*(src._brain)) ){
	std::cout << "Cat copy constructor called" << std::endl;

	this->_type = src.getType();
}

Cat &	Cat::operator=( Cat const & rhs ) {
	std::cout << "Cat assignment operator called" << std::endl;

	this->_type = rhs.getType();

	delete _brain;
	_brain = new Brain( *(rhs._brain) );
	return *this;
}

Cat::~Cat( ) {
	delete	_brain;
	std::cout << "~Cat called" << std::endl;
}

/*****************************************************************************/
/*                             Member functions                              */
/*****************************************************************************/

void	Cat::makeSound( ) const {
	std::cout << this->_type << ": \"meowww\"" << std::endl;
}

void		Cat::spewIdea( ) const {
	static	uint index = 0;

	std::cout << getType() << "'s random thought : " 
		<< _brain->getIdea( index ) << std::endl;
	
	index++;
	index %= 100;
	return ;
}

/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/


std::ostream &	operator<<( std::ostream & o, Cat const & rhs ) {

	o << rhs.getType();
	return o;
}
