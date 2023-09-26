#include "AMateria.hpp"

/*****************************************************************************/
/*                          Constructors/Destructors                         */
/*****************************************************************************/

AMateria::AMateria( AMateria const & src ) {
	*this = src;
}

AMateria::AMateria( std::string const & type ) : _type( type ) { }

AMateria &	AMateria::operator=( AMateria const & rhs ) {
	this->_type = rhs._type;
	return *this;
}

/*****************************************************************************/
/*                              Getters/Setters                              */
/*****************************************************************************/

std::string	const &	AMateria::getType( ) const {
	return this->_type;
}

/*****************************************************************************/
/*                              Member functions                             */
/*****************************************************************************/

void	AMateria::use( ICharacter& target ) {
	std::cout << "\n* "
		<< this->_type << " called AMateria::use() on " << target
		<< ". " << this->_type << " has no default action!"
		<< " *" << std::endl;
}

/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/

std::ostream &	operator<<( std::ostream & o, AMateria const & rhs ) {

	o << rhs.getType();
	return o;
}
