#include "StorageObject.hpp"


/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

StorageObject::StorageObject( ) :
	_nbStored(0)
{
	for (uint i = 0; i < STORAGE_MAX; i++)
		this->_storage[i] = nullptr;
}

StorageObject::StorageObject( StorageObject const & src ) { 
	for (uint i = 0; i < src._nbStored; i++)
		this->_storage[i] = src._storage[i];	
}

StorageObject &	StorageObject::operator=( StorageObject const & rhs ) {	
	for (uint i = 0; i < rhs._nbStored; i++)
		this->_storage[i] = rhs._storage[i];

	return *this; 
}

StorageObject::~StorageObject( ) { }


/*****************************************************************************/
/*                              Member functions                             */
/*****************************************************************************/


bool	StorageObject::addMateria( AMateria * newM )
{
	if (this->_nbStored == STORAGE_MAX)
		return false;

	this->_storage[ this->_nbStored++ ] = newM;
	this->_nbStored++;
	return true;
}

void	StorageObject::clearStorage( )
{
	while (_nbStored)
		delete _storage[--_nbStored];
}
