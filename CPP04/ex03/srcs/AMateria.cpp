#include "AMateria.hpp"

/*****************************************************************************/
/*                          Constructors/Destructors                         */
/*****************************************************************************/

AMateria::AMateria( AMateria const & src ) {
	*this = src;
}

AMateria &	AMateria::operator=( AMateria const & rhs ) {
	this->_type = rhs.getType();
	this->_message = rhs.getMessage();
	return *this;
}

/*****************************************************************************/
/*                              Getters/Setters                              */
/*****************************************************************************/

std::string	const &	AMateria::getType( ) const {
	return this->_type;
}

std::string	const &	AMateria::getMessage( ) const {
	return this->_message;
}

/*****************************************************************************/
/*                              Member functions                             */
/*****************************************************************************/

void	AMateria::use( ICharacter& target ) {
	std::cout << "\n";
	std::cout << this->_type << "  " << _message << " " << target << "\n" ;
	std::cout << std::endl;
}

/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/

std::ostream &	operator<<( std::ostream & o, AMateria const & rhs ) {

	o << rhs.getType();
	return o;
}
