#include "Character.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

Character::Character( ) :
	_name( "noName" ),
	_nbItems( 0 ),
	_nbDroppedItems( 0 )
{
	std::cout << "Character constructor called by " << _name << std::endl;

	for (int i = 0; i < INVENTORY_MAX; i++)		
		this->_inventory[i] = NULL;

	for (int i = 0; i < DROPPED_MAX; i++)
		this->_droppedItems[i] = NULL;

}



Character::Character( std::string const & name ) :
	_name( name ),
	_nbItems( 0 ),
	_nbDroppedItems( 0 )
{
	std::cout << "Character constructor called by " << _name << std::endl;

	for (int i = 0; i < INVENTORY_MAX; i++)		
		this->_inventory[i] = NULL;

	for (int i = 0; i < DROPPED_MAX; i++)
		this->_droppedItems[i] = NULL;

}



Character::Character( Character const & src ) {
	std::cout << "Character copy constructor called by " << _name << std::endl;
	*this = src;
}



Character::~Character( ) {
		
	for (uint i = 0; i < INVENTORY_MAX; i++)
		delete _inventory[i];

	while (_nbDroppedItems)
		delete _droppedItems[--_nbDroppedItems];
	
	std::cout << "~Character destructor called by " << _name << std::endl;
}




/*****************************************************************************/
/*                           Assignment operator                             */
/*****************************************************************************/

Character &	Character::operator=( Character const & rhs ) {

	std::cout << "Character assignment operator called by " << _name << std::endl;

	this->~Character();

	this->_name = rhs.getName();

	/*		I settled for cloning all the source items,			*
	 *		as a shallow copy causes issues with later deletion	*/

	// Update inventory
	for (uint i = 0; i < INVENTORY_MAX; i++) {

		_inventory[i] = (rhs._inventory[i] ? rhs._inventory[i]->clone() : NULL);
	}

	this->_nbItems = rhs._nbItems;


	// Update droppedItems
	for (uint i = 0; i < rhs._nbDroppedItems; i++) {
		
		this->_inventory[i] = rhs._inventory[i]->clone();	
	}

	this->_nbDroppedItems = rhs._nbDroppedItems;

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

	static int destroyIndex = 0;

	if ( newMateria == NULL )
		return ;

	if ( _nbItems == INVENTORY_MAX ) {
		
		// Design choice, but it's either this or delete() the pointer
		unequip(destroyIndex);

		++destroyIndex %= INVENTORY_MAX;	// roll around to next index
	}

	// To be completed in for loop below
	std::cout << *this << " equips the " << *newMateria;

	_nbItems++;

	for (int i = 0; i < INVENTORY_MAX; i++) {

		// Find the next available slot, informs user on stdout
		if ( !_inventory[i] ) {

			std::cout << " in slot [ " << i << " ]" << std::endl;
			
			_inventory[i] = newMateria;
			return ;
		}
	}

}	



void Character::unequip( int idx ) {

	static int destroyIndex = 0;

	if ( idx < 0 || idx >= NB_MATERIA || !_inventory[idx] ) {
		std::cerr << "Oops. " << *this 
			<< " has nothing in that slot." << std::endl;
		
		return ;
	}

	std::cout << *this << " drops the " << _inventory[idx]->getType();

	if ( _nbDroppedItems ) {
		std::cout << ", along with the " << _nbDroppedItems
			<< " other thing" << ( _nbDroppedItems > 1 ? "s" : "" );
	}
		
	std::cout << "." << std::endl;


	if ( _nbDroppedItems >= DROPPED_MAX ) {
		
		std::cout << _name << " dropped too many items..." << "\n"
			<< "Some " << *_droppedItems[destroyIndex]
			<< " randomly vanishes into thin air!" << "\n" << std::endl;

		delete _droppedItems[destroyIndex];

		_droppedItems[destroyIndex] = _droppedItems[--_nbDroppedItems];

		++destroyIndex %= DROPPED_MAX;
	}

	_droppedItems[_nbDroppedItems] = _inventory[idx];

	_nbDroppedItems += 1;

	_inventory[idx] = NULL;

	_nbItems--;
	
}



/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/

std::ostream &	operator<<( std::ostream & o, ICharacter const & rhs ) {

	o << rhs.getName();
	return o;
}
