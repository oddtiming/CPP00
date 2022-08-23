#ifndef SCAVTRAP_HPP_
# define SCAVTRAP_HPP_

# include <string>
# include <iostream>
# include <iomanip>
# include "ClapTrap.hpp"

# define SCAV_HP 100
# define SCAV_EP 50
# define SCAV_AD 20
# define LUCK_FACTOR 3
# define GUARD_EMOJI "\U000026A1"

class ScavTrap : virtual public ClapTrap {

protected:
/* Attributes */
	bool		_guardMode;		// can be activated whrough guardGate
	int			_isLucky;		// guardMode will grant unexpected luck two times out of 3
	bool		_updateEnergy( );
	bool		_updateLuckFactor( );

public:
/* Ctors/Dtors */
	ScavTrap( );
	ScavTrap( std::string name );
	ScavTrap( ScavTrap const & src );

	~ScavTrap( );

	ScavTrap &	operator=( ScavTrap const & rhs );	
	
/* New member function */
	void		guardGate( );	// activates special guard mode. Grants the ScavTrap unexpected luck
	
/* ClapTrap functions overload to account for guardMode */
	void		attack( std::string& target );
	void		takeDamage( uint damage );
	void		beRepaired( uint damage );

};

std::ostream & operator<<( std::ostream & o, ScavTrap const & s );

#endif // SCAVTRAP_HPP_
