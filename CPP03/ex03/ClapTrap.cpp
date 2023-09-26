#include "ClapTrap.hpp"

/*****************************************************************************/
/*                         Constructors/Destructors                          */
/*****************************************************************************/

ClapTrap::ClapTrap( ) : 
	_name( "default_ClapTrap" ),
	_hitPts( CLAP_HP ),
	_energyPts( CLAP_EP ),
	_attackDmg( CLAP_AD ) {
	std::cout << __FUNCTION__ << " default constructor called. Name given is " 
		<< _name << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ) : 
	_name(name),
	_hitPts( CLAP_HP ),
	_energyPts( CLAP_EP ),
	_attackDmg( CLAP_AD ) {

	std::cout << __FUNCTION__ << " parametric constructor called with name " 
		<< name << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {
	std::cout << __FUNCTION__ << " copy constructor called" << std::endl;

	*this = src;
}

ClapTrap &	ClapTrap::operator=( ClapTrap const & rhs ) {
	std::cout << __FUNCTION__ << " assignment operator called" << std::endl;

	this->_name = rhs.getName();
	return *this;
}

ClapTrap::~ClapTrap( ) {
	std::cout << __FUNCTION__ << " destructor called on " << *this << std::endl;
}


/*****************************************************************************/
/*                             Getters/Setters                               */
/*****************************************************************************/


std::string	ClapTrap::getName( ) const {
	return this->_name;
}

uint	ClapTrap::getHP( ) const {
	return this->_hitPts;
}

uint	ClapTrap::getEP( ) const {
	return this->_energyPts;
}

uint	ClapTrap::getAD( ) const {
	return this->_attackDmg;
}


/*****************************************************************************/
/*                             Member functions                              */
/*****************************************************************************/

void		ClapTrap::attack( std::string & target ) {

	if (!_updateEnergy( ))
		return ;
	
	std::cout << "Claptrap " << *this << " attacks \"" << target << "\".";
	std::cout << " It deals " << this->_attackDmg << " damage!" << "\n" << std::endl;

	return ;
}

void		ClapTrap::takeDamage( uint damage ) {

	std::cout << "\nClaptrap " << *this << " takes " << damage << " damage. Fuckin ouch." << std::endl;

	_updateHealth( -damage );
	
	return ;
}

void		ClapTrap::beRepaired( uint amount ) {

	if (!_updateEnergy( ))
		return ;

	std::cout << "Claptrap " << *this << " repairs itself by " << amount << " hitPoints!" << std::endl;

	_updateHealth( amount );

	return ;
}

bool		ClapTrap::_updateEnergy( ) {

	if (!this->_energyPts) {

		std::cout << "No can do! ClapTrap " << *this << " has no more energy points" << "\n" << std::endl;
		return false;
	}


	std::cout << "\tEnergy: [ " << this->_energyPts << " ]\t===>";
	this->_energyPts--;
	std::cout << "\t[ " 	<< this->_energyPts << " ]" << std::endl;

	return true;
}

void		ClapTrap::_updateHealth( int amount ) {

	std::cout << "\tHP: [ " << this->_hitPts << " ]\t===>";

	if ( !this->_hitPts && amount < 0 ) {
		std::cout << "\tShame on you! Leave the guy alone :( " << "\n" << std::endl;
		return ;
	}

	if (-amount > (int)this->_hitPts)
		amount = -this->_hitPts;

	this->_hitPts += amount;

	std::cout << "\t[ " 	<< this->_hitPts << " ]" << "\n" << std::endl;
	
	if ( !this->_hitPts && amount )
		std::cout << "\t!!! ClapTrap " << *this << " do be pretty done. sad." << " !!!\n" << std::endl;

	else if ( amount > 0 && this->_hitPts >= CLAP_HP )
		std::cout << *this << " is as good as new!" << "\n" << std::endl;

	return ;
}


/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/

std::ostream &	operator<<( std::ostream & o, ClapTrap const & rhs ) {

	o << rhs.getName();
	return o;
}
