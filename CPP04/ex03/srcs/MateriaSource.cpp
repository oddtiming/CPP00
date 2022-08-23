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


	std::cout << "createMateria() wth materia " << type << std::endl;
	AMateria *	copy;

	for (uint i = 0; i < _nbItems; i++) {

		std::cout << "i = " << i << std::endl;
		std::cout << "_library[i]->getType() = " << _library[i]->getType() << std::endl;
		std::cout << "i = " << i << std::endl;
		if ( _library[i]->getType() == type ) {
			copy = _library[i]->clone();
			return copy;
		}
		
	}
	
	return NULL;
}

void			MateriaSource::learnMateria( AMateria * src ){

	if ( this->_nbItems == NB_MATERIA )
		return ;

	this->_nbItems++;

	this->_library[this->_nbItems] = src->clone();

}
