#include "ClapTrap.hpp"

ClapTrap::ClapTrap( ) : 
	_name( "Unnamed_ClapTrap" ),
	_hitPts( CLAP_HP ),
	_energyPts( CLAP_EP ),
	_attackDmg( CLAP_AD ) {

	std::cout << __FUNCTION__ << " constructor called" << std::endl;
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




std::string	ClapTrap::getName( ) const {
	return this->_name;
}

void		ClapTrap::attack( std::string & target ) {

	if (!_updateEnergy( ))
		return ;
	
	std::cout << *this << " attacks \"" << target << "\".";
	std::cout << " It deals " << this->_attackDmg << " damage!" << std::endl;

	return ;
}

void		ClapTrap::takeDamage( uint damage ) {

	std::cout << "\n" << *this << " takes " << damage << " damage. Fuckin ouch." << std::endl;

	_updateHealth( -damage );
	
	return ;
}

void		ClapTrap::beRepaired( uint amount ) {

	if (!_updateEnergy( ))
		return ;

	std::cout << *this << " repairs itself by " << amount << " hitPoints!" << std::endl;

	_updateHealth( amount );

	this->_energyPts--;
	
	return ;
}

bool		ClapTrap::_updateEnergy( ) {

	if (!this->_energyPts) {

		std::cout << "No can do! " << *this << " has no more energy points" << std::endl;
		return false;
	}


	std::cout << "\tEnergy: [ " << this->_energyPts << " ]\t===>";
	this->_energyPts--;
	std::cout << "\t[ " 	<< this->_energyPts << " ]" << std::endl;

	return true;
}

void		ClapTrap::_updateHealth( int amount ) {

	if ( amount < 0 && !this->_hitPts ) {
		std::cout << "\tShame on you! Leave the dead alone :( " << std::endl;
		return ;
	}
	else if (-amount > (int)this->_hitPts)
		amount = -this->_hitPts;

	std::cout << "\tHP: [ " << this->_hitPts << " ]\t===>";

	this->_hitPts += amount;

	std::cout << "\t[ " 	<< this->_hitPts << " ]" << std::endl;
	
	if ( !this->_hitPts )
		std::cout << "\n" << *this << " do be pretty dead. sad." << "\n" << std::endl;

	return ;
}

std::ostream &	operator<<( std::ostream & o, ClapTrap const & rhs ) {

	o << rhs.getName();
	return o;
}
