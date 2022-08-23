#include "Character.hpp"

Character::Character( ) :
	_name( "noName" ),
	_nbItems( 0 ),
	_nbDroppedItems( 0 )
{
	std::cout << "Character constructor called  " << std::endl;
}

Character::Character( std::string const & name ) :
	_name( name ),
	_nbItems( 0 ),
	_nbDroppedItems( 0 )
{
	std::cout << "Character constructor called  for " << name << std::endl;
}

Character::Character( Character const & src ) {
	std::cout << "Character copy constructor called  " << std::endl;
	*this = src;
}

Character &	Character::operator=( Character const & rhs ) {

	while (_nbDroppedItems)
		delete _droppedItems[--_nbDroppedItems];
		
	while (_nbItems)
		delete _inventory[--_nbItems];

	this->_name = rhs.getName();

	for (int i = 0; i < rhs._nbItems; i++) {
		_inventory[i] = rhs._inventory[i];
		_nbItems++;
	}
	
	return *this;
}

Character::~Character( ) {

	while (_nbDroppedItems)
		delete _droppedItems[--_nbDroppedItems];
		
	while (_nbItems)
		delete _inventory[--_nbItems];

	std::cout << "~Character destructor called  " << std::endl;
}


std::string const &	 Character::getName( ) const {
	return this->_name;
}

void Character::use( int idx, ICharacter & target) {

	if (idx >= _nbItems)
		return ;
	
	this->_inventory[idx]->use( target );
}	

void Character::equip( AMateria * newMateria) {

	if ( _nbItems == NB_INVENTORY_SLOTS )
		delete _inventory[_nbItems - 1];
	
	_inventory[_nbItems] = newMateria->clone();
	
	if ( _nbItems != NB_INVENTORY_SLOTS )
		_nbItems++;
}	

void Character::unequip( int idx ) {

	_droppedItems[_nbDroppedItems] = _inventory[idx]->clone();

	_nbDroppedItems++;

	delete _inventory[idx];
	
	for (int i = idx; i < _nbItems - 1; i++)
		_inventory[i] = _inventory[i + 1];

	_nbItems--;
	
}	
