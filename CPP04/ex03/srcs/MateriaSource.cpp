#include "MateriaSource.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

MateriaSource::MateriaSource( ) : _nbItems( 0 ) {
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource( MateriaSource const & src ) {
	std::cout << "MateriaSource copy constructor called" << std::endl;

	*this = src;
}

MateriaSource &	MateriaSource::operator=( MateriaSource const & rhs ) {

	uint i = rhs.getNbItems();
	
	while (i--)
		this->_library[i] = rhs.getLibraryItem( i );
		
	return *this;
}

MateriaSource::~MateriaSource( ) {

	while (_nbItems--)
		delete	_library[_nbItems];

	std::cout << "~MateriaSource called" << std::endl;
}

/*****************************************************************************/
/*                              Getters/Setters                              */
/*****************************************************************************/

uint			MateriaSource::getNbItems( ) const {
	return this->_nbItems;
}

AMateria *		MateriaSource::getLibraryItem( uint index ) const {

	if (index >= _nbItems)
		return NULL;
	
	return _library[index];
}

/*****************************************************************************/
/*                              Member functions                             */
/*****************************************************************************/

/**
 * @return AMateria* 
 * 
 * 		Returns a pointer to a copy of `type' AMateria
 * 	if it is known to the MateriaSource
 * 
 * 		Returns NULL otherwise
 */
AMateria*		MateriaSource::createMateria( std::string const & type ){

	if ( type.empty() )
		return NULL;

	for (uint i = 0; i < _nbItems; i++) {

		if ( _library[i]->getType() == type ) {
	
			return _library[i]->clone();
		}
	}
	
	std::cout << "MateriaSource doesn't know " << type << std::endl;

	return NULL;
}

/**
 * 		Will only accept 4 Materia. will delete `src' if full
 */
void			MateriaSource::learnMateria( AMateria * src ){

	// Check whether there is space
	if ( this->_nbItems >= NB_MATERIA ) {

		std::cerr << __FUNCTION__ << " error: inventory is full." << std::endl;

		delete src;

		return ;
	}

	// Assign new item to library
	this->_library[this->_nbItems] = src;

	// Update nbItems
	this->_nbItems++;

}
