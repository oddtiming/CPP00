#include "ScavTrap.hpp"

/*****************************************************************************/
/*                         Constructors/Destructors                          */
/*****************************************************************************/

ScavTrap::ScavTrap( ) : ClapTrap()
{

	std::cout << __FUNCTION__ << "( ) default constructor called. Name given is " 
		<< this->getName() << std::endl;
	this->_hitPts = SCAV_HP;
	this->_energyPts = SCAV_EP;
	this->_attackDmg = SCAV_AD;
	this->_isLucky = 0;
	this->_guardMode = false;

	return ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{

	std::cout << __FUNCTION__ << "( " << name << " ) parametric constructor called with name " 
		<< name << std::endl;
	this->_hitPts = SCAV_HP;
	this->_energyPts = SCAV_EP;
	this->_attackDmg = SCAV_AD;
	this->_isLucky = 0;
	this->_guardMode = false;

	return ;
}

ScavTrap::ScavTrap( ScavTrap const & src ) {
	std::cout << __FUNCTION__ << " copy constructor called" << std::endl;

	*this = src;
}

ScavTrap &	ScavTrap::operator=( ScavTrap const & rhs ) {
	std::cout << __FUNCTION__ << " assignment operator called" << std::endl;

	this->_name = rhs.getName();
	return *this;
}

ScavTrap::~ScavTrap( ) {
	std::cout << __FUNCTION__ << " destructor called on " << *this << std::endl;
}

/*****************************************************************************/
/*                            New member function                            */
/*****************************************************************************/

void		ScavTrap::guardGate( ) {

	std::cout << std::setw( 80 ) << std::setfill('*') << "\n";
	std::cout << "\t\t\t" << *this 
		<< " is now in guard mode!" << std::endl;
	std::cout << std::setw( 80 ) << std::setfill('*') << "\n" << std::endl;

	this->_guardMode = true;

	return ;
}


/*****************************************************************************/
/*            ClapTrap functions overload to account for guardMode           */
/*****************************************************************************/

void		ScavTrap::attack( std::string & target ) {

	if (!_updateEnergy( ))
		return ;
	
	uint	damage = this->_attackDmg;
	

	std::cout << *this << " attacks \"" << target << "\".";

	// Guard mode gives a one in two chance of positive outcomes
	if ( this->_guardMode && _updateLuckFactor() ) {

		std::cout << "\n\t" << GUARD_EMOJI  << " Guard mode gives " 
			<< *this << " a critical hit !" << std::endl;

		
		std::cout << "\tDamage: [ " << damage << " ]\t===>";
		damage *= 2;
		std::cout << "\t[ " 	<< damage << " ]" << std::endl;

	}

	std::cout << " It deals " << damage << " damage!" << "\n" <<  std::endl;

	return ;
}

void		ScavTrap::takeDamage( uint damage ) {

	// Guard mode gives a two in three chance of positive outcomes
	if ( this->_guardMode && _updateLuckFactor() ) {

		std::cout << "\t" << GUARD_EMOJI  << " Guard mode gives " << *this << " an unexpected protection !" << "\n"
			<< "\t" << *this << " takes half the damage!" << GUARD_EMOJI << std::endl;

		
		std::cout << "\tDamage: [ " << damage << " ]\t===>";
		damage /= 2;
		std::cout << "\t[ " 	<< damage << " ]" << std::endl;

	}
	
	std::cout << "\n" << *this << " takes " << damage << " damage. Fuckin ouch." << std::endl;

	_updateHealth( -damage );
	
	return ;
}

void		ScavTrap::beRepaired( uint amount ) {


	if (!_updateEnergy( ))
		return ;


	// Guard mode gives a two in three chance of positive outcomes
	if ( this->_guardMode && _updateLuckFactor() ) {

		std::cout << "\t" << GUARD_EMOJI  << " Guard mode gives " << *this << " an unexpected boost !" << "\n\t"
			<< *this << " repairs itself by twice the amount!" << GUARD_EMOJI << std::endl;

		std::cout << "\tRepair: [ " << amount << " ]\t===>";
		amount *= 2;
		std::cout << "\t[ " 	<< amount << " ]" << std::endl;
	}

	std::cout << *this << " repairs itself by " << amount << " hitPoints!" << std::endl;

	_updateHealth( amount );
	
	return ;
}


/*****************************************************************************/
/*                          Private member functions                         */
/*****************************************************************************/

bool		ScavTrap::_updateLuckFactor( ) {

	this->_isLucky++;
	this->_isLucky %= LUCK_FACTOR;

	return this->_isLucky;
}

bool		ScavTrap::_updateEnergy( ) {


	// Guard mode gives a two in three chance of positive outcomes
	if ( this->_guardMode && _updateLuckFactor() ) {

		std::cout << "\t" << GUARD_EMOJI << " Guard mode gives " << *this << " unexpected energy!"
			<< " No Energy spent." << GUARD_EMOJI << std::endl;
		return true;
	}

	if (!this->_energyPts) {

		std::cout << "No can do! " << *this << " has no more energy points" << std::endl;
		return false;
	}

	std::cout << "\tEnergy: [ " << this->_energyPts << " ]\t===>";
	this->_energyPts--;
	std::cout << "\t[ " 	<< this->_energyPts << " ]" << std::endl;

	return true;
}

/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/

std::ostream &	operator<<( std::ostream & o, ScavTrap const & rhs ) {

	o << rhs.getName();
	return o;
}
