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
}


Character::Character( Character const & src ) {
	this->_name = src.getName();
	std::cout << "Copy constructor called by " << _name << std::endl;


	// Update inventory
	for (uint i = 0; i < INVENTORY_MAX; i++) {
		_inventory[i] = (src._inventory[i] ? src._inventory[i]->clone() : NULL);
	}
	this->_nbItems = src._nbItems;

	// dropped items are created afresh everytime
	this->_nbStorages = 1;
	this->_droppedItems = new StorageObject[ _nbStorages ];

	
	*this = src;
}


Character::~Character( ) {
	std::cout << "~Character destructor called by " << _name << std::endl;
		
	for (uint i = 0; i < INVENTORY_MAX; i++)
		delete _inventory[i];

	while ( _nbStorages-- )
		_droppedItems[ _nbStorages ].deleteStorage();
	
	delete [] _droppedItems;
}


/*****************************************************************************/
/*                           Assignment operator                             */
/*****************************************************************************/

/**
 * 		Copy assignment operator does not copy dropped items
 */
Character &	Character::operator=( Character const & rhs ) {

	std::cout << "Character assignment operator called by " << _name << std::endl;

	this->~Character();

	this->_name = rhs.getName();

	// Update inventory
	for (uint i = 0; i < INVENTORY_MAX; i++) {
		_inventory[i] = (rhs._inventory[i] ? rhs._inventory[i]->clone() : NULL);
	}
	this->_nbItems = rhs._nbItems;

	// dropped items are created afresh everytime
	this->_nbStorages = 1;
	this->_droppedItems = new StorageObject[ _nbStorages ];

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
		
		std::cerr << *this
				  << " cannot equip anymore items! Unequip something first."
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

		_droppedItems = newStorage;
		_droppedItems[_nbStorages - 1].addMateria(_inventory[ idx ]);

	}

	_inventory[idx] = nullptr;

	_nbItems--;
	
}


/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/

std::ostream &	operator<<( std::ostream & o, ICharacter const & rhs ) {

	o << rhs.getName();
	return o;
}
