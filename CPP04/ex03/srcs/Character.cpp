#include "Character.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

Character::Character( ) :
	_name( "noName" ),
	_nbItems( 0 ),
	_nbStorages( 1 ),
	_droppedItems( new StorageObject[ _nbStorages ])
{
	std::cout << "Character constructor called by " << _name << std::endl;

	for (int i = 0; i < INVENTORY_MAX; i++)		
		this->_inventory[i] = nullptr;

	// for (int i = 0; i < DROPPED_MAX; i++)
	// 	this->_droppedItems[i] = nullptr;

}


Character::Character( std::string const & name ) :
	_name( name ),
	_nbItems( 0 ),
	_nbStorages( 1 ),
	_droppedItems( new StorageObject[ _nbStorages ])
{
	std::cout << "Character constructor called by " << _name << std::endl;

	for (int i = 0; i < INVENTORY_MAX; i++)		
		this->_inventory[i] = nullptr;

	// for (int i = 0; i < DROPPED_MAX; i++)
	// 	this->_droppedItems[i] = nullptr;

}


Character::Character( Character const & src ) {
	std::cout << "Character copy constructor called by " << _name << std::endl;
	*this = src;
}


Character::~Character( ) {
	std::cout << "~Character destructor called by " << _name << std::endl;
		
	for (uint i = 0; i < INVENTORY_MAX; i++)
		delete _inventory[i];

	// while ( _nbStorages )
	// 	delete _droppedItems[--_nbStorages];
	
	delete [] _droppedItems;

}



/*****************************************************************************/
/*                           Assignment operator                             */
/*****************************************************************************/

// Character &	Character::operator=( Character const & rhs ) {

// 	std::cout << "Character assignment operator called by " << _name << std::endl;

// 	this->~Character();

// 	this->_name = rhs.getName();

// 	/*		I settled for cloning all the source items,			*
// 	 *		as a shallow copy causes issues with later deletion	*/

// 	// Update inventory
// 	for (uint i = 0; i < INVENTORY_MAX; i++) {

// 		_inventory[i] = (rhs._inventory[i] ? rhs._inventory[i]->clone() : NULL);
// 	}

// 	this->_nbItems = rhs._nbItems;


// 	// Update droppedItems
// 	for (uint i = 0; i < rhs._nbDroppedItems; i++) {
		
// 		this->_inventory[i] = rhs._inventory[i]->clone();	
// 	}

// 	this->_nbDroppedItems = rhs._nbDroppedItems;

// 	return *this;
// }

Character &	Character::operator=( Character const & rhs ) {

	std::cout << "Character assignment operator called by " << _name << std::endl;


	// This might be causing an issue !
	this->~Character();

	this->_name = rhs.getName();

	// Update inventory
	/*		I settled for cloning all the source items,			*
	 *		as a shallow copy causes issues with later deletion	*/
	for (uint i = 0; i < INVENTORY_MAX; i++) {

		_inventory[i] = (rhs._inventory[i] ? rhs._inventory[i]->clone() : NULL);
	}

	this->_nbItems = rhs._nbItems;


	// Update droppedItems
	this->_droppedItems = new StorageObject[rhs._nbStorages];

	for (uint i = 0; i < rhs._nbStorages - 1; i++) {
		this->_droppedItems[i] = rhs._droppedItems[i];
	}

	this->_nbStorages = rhs._nbStorages;


	return *this;
}



/*****************************************************************************/
/*                              Getters/Setters                              */
/*****************************************************************************/

std::string const &	 Character::getName( ) const {
	return this->_name;
}



/*****************************************************************************/
/*                              Member functions                             */
/*****************************************************************************/

void Character::use( int idx, ICharacter & target) {

	if ( idx < 0 || idx >= NB_MATERIA || this->_inventory[idx] == NULL ) {

		std::cerr << "Oops. " << *this << " doesn't know that." << std::endl;
		
		return ;
	}
	
	this->_inventory[idx]->use( target );
}



void Character::equip( AMateria * newMateria) {

	if ( newMateria == nullptr )
		return ;

	if ( _nbItems == INVENTORY_MAX ) {
		
		std::cerr << "Apparently, "
				  << *this
				  << " cannot deal with dropping stuff, so you're shit out of luck."
				  << " Hope you kept a pointer to this AMateria ¯\\_(ツ)_/¯"
				  << std::endl;
		return ;
	}

	// To be completed in for loop below
	std::cout << *this << " equips the " << *newMateria;

	_nbItems++;

	for (uint i = 0; i < INVENTORY_MAX; i++) {

		// Find the next available slot, informs user on stdout
		if ( !_inventory[i] ) {
			std::cout << " in slot [ " << i << " ]" << std::endl;
			
			_inventory[i] = newMateria;
			return ;
		}
	}

}


void Character::unequip( int idx ) {

	if ( idx < 0 || idx >= NB_MATERIA || !_inventory[idx] ) {
		std::cerr << "Oops. " << *this 
				  << " has nothing in that slot." << std::endl;
		
		return ;
	}

	std::cout << *this 
			  << " drops the " 
			  << _inventory[idx]->getType() 
			  << "." << std::endl;

	if ( _droppedItems[_nbStorages - 1].addMateria(_inventory[ idx ]) == false ) {
		StorageObject *		newStorage = new StorageObject[++_nbStorages];

		for (uint i = 0; i < _nbStorages - 1; i++) {
			newStorage[i] = _droppedItems[i];
		}

		delete [] _droppedItems;

		_droppedItems[_nbStorages - 1].addMateria(_inventory[ idx ]);

	}

	_inventory[idx] = nullptr;

	_nbItems--;
	
}

// void Character::unequip( int idx ) {

// 	static int destroyIndex = 0;

// 	if ( idx < 0 || idx >= NB_MATERIA || !_inventory[idx] ) {
// 		std::cerr << "Oops. " << *this 
// 				  << " has nothing in that slot." << std::endl;
		
// 		return ;
// 	}

// 	std::cout << *this << " drops the " << _inventory[idx]->getType();

// 	if ( _nbDroppedItems ) {
// 		std::cout << ", along with the " << _nbDroppedItems
// 				  << " other thing" << ( _nbDroppedItems > 1 ? "s" : "" );
// 	}
		
// 	std::cout << "." << std::endl;


// 	if ( _nbDroppedItems >= DROPPED_MAX ) {
		
// 		std::cerr << _name << " dropped too many items..." << "\n"
// 				  << "Some " << *_droppedItems[destroyIndex]
// 				  << " randomly vanishes into thin air!" << "\n" 
// 				  << "\t\t *** (that's a euphemism for you just caused memory leaks,"
// 				  << " because apparently it's better than using delete?) ***"
// 				  << std::endl;

// 		// delete _droppedItems[destroyIndex];

// 		_droppedItems[destroyIndex] = _droppedItems[--_nbDroppedItems];

// 		++destroyIndex %= DROPPED_MAX;
// 	}

// 	_droppedItems[_nbDroppedItems] = _inventory[idx];

// 	_nbDroppedItems += 1;

// 	_inventory[idx] = nullptr;

// 	_nbItems--;
	
// }



/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/

std::ostream &	operator<<( std::ostream & o, ICharacter const & rhs ) {

	o << rhs.getName();
	return o;
}
