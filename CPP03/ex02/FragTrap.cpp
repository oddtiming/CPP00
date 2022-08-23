#include "FragTrap.hpp"

/*****************************************************************************/
/*                         Constructors/Destructors                          */
/*****************************************************************************/

FragTrap::FragTrap( ) : ClapTrap() {

	std::cout << __FUNCTION__ << "( ) default constructor called. Name given is " 
		<< this->getName() << std::endl;
	this->_hitPts = FRAG_HP;
	this->_energyPts = FRAG_EP;
	this->_attackDmg = FRAG_AD;

	return ;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name ) {

	std::cout << __FUNCTION__ << "( " << _name << " ) parametric constructor called" << std::endl;
	this->_hitPts = FRAG_HP;
	this->_energyPts = FRAG_EP;
	this->_attackDmg = FRAG_AD;

	return ;
}

FragTrap::FragTrap( FragTrap const & src ) {
	std::cout << __FUNCTION__ << " copy constructor called" << std::endl;

	*this = src;
}

FragTrap &	FragTrap::operator=( FragTrap const & rhs ) {
	std::cout << __FUNCTION__ << " assignment operator called" << std::endl;

	this->_name = rhs.getName();
	return *this;
}

FragTrap::~FragTrap( ) {
	std::cout << __FUNCTION__ << " destructor called on " << *this << std::endl;
}

/*****************************************************************************/
/*                            New member function                            */
/*****************************************************************************/

void		FragTrap::highFivesGuys( ) {

	if (this->_updateEnergy())
		std::cout << *this << " high fives random people! They seem to like it..." << "\n" << std::endl;

	return ;
}

/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/

std::ostream &	operator<<( std::ostream & o, FragTrap const & rhs ) {

	o << rhs.getName();
	return o;
}
