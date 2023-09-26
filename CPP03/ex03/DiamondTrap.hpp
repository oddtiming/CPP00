#ifndef DIAMONDTRAP_HPP_
# define DIAMONDTRAP_HPP_

# include <string>
# include <iostream>
# include <iomanip>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

private:
	std::string	_name;
	uint		_hitPts;
	uint		_energyPts;
	uint		_attackDmg;

public:
/* Ctors/Dtors */
	DiamondTrap( );
	DiamondTrap( std::string name );
	DiamondTrap( DiamondTrap const & src );

	~DiamondTrap( );

	DiamondTrap &	operator=( DiamondTrap const & rhs );	

/* New member function */
	void		whoAmI( );	// does nothing but print a log msg to stdout
	std::string	getName( );	// does nothing but print a log msg to stdout
	using		ScavTrap::attack;
	using		ScavTrap::getName;
	using		FragTrap::beRepaired;

};


#endif // DIAMONDTRAP_HPP_
