#include "DiamondTrap.hpp"

/*****************************************************************************/
/*                         Constructors/Destructors                          */
/*****************************************************************************/

DiamondTrap::DiamondTrap( ) 
	: ScavTrap( ), FragTrap( ), _name( "default" ) {

	std::cout << __FUNCTION__ << "( ) default constructor called. Name given is " 
		<< this->_name << std::endl;
	this->_name = ( "default_clap_name" );
	this->_hitPts = FragTrap::getHP();
	this->_energyPts = ScavTrap::getEP();
	this->_attackDmg = FragTrap::getAD();

	return ;
}

DiamondTrap::DiamondTrap( std::string name ) 
	: ClapTrap( name + "_clap_name" ), ScavTrap( name ), FragTrap( name )
{

	std::cout << __FUNCTION__ << "( " << _name << " ) parametric constructor called" << std::endl;
	this->_name = name;
	this->_hitPts = FragTrap::getHP();
	this->_energyPts = ScavTrap::getEP();
	this->_attackDmg = FragTrap::getAD();

	return ;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src ) {
	std::cout << __FUNCTION__ << " copy constructor called" << std::endl;

	*this = src;
}

DiamondTrap &	DiamondTrap::operator=( DiamondTrap const & rhs ) {
	std::cout << __FUNCTION__ << " assignment operator called" << std::endl;

	this->_name = rhs.FragTrap::getName();
	return *this;
}

DiamondTrap::~DiamondTrap( ) {
	std::cout << __FUNCTION__ << " destructor called on " << _name << std::endl;
}

/*****************************************************************************/
/*                            New member function                            */
/*****************************************************************************/

void		DiamondTrap::whoAmI( ) {

	std::cout << "\n\t\twhoamI()\n";
	std::cout << "_name \t\t\t: " << _name << std::endl;
	std::cout << "ClapTrap::_name\t: " << ClapTrap::_name << "\n" << std::endl;
	return ;
}

std::string		DiamondTrap::getName( ) { return DiamondTrap::_name; }
