#ifndef CLAPTRAP_HPP_
# define CLAPTRAP_HPP_

# include <string>
# include <iostream>

# define CLAP_HP 10
# define CLAP_EP 10
# define CLAP_AD 0

class ClapTrap {

/**
 * 		Here theaccess modifier changes for the base class,
 * 		as you want your child classes to be able to access them
 * 
 */
protected:
/* Attributes */
	std::string	_name;
	uint		_hitPts;
	uint		_energyPts;
	uint		_attackDmg;

/* Functions */
	void		_updateHealth( int change );	// damage is negative, repair is positive
	bool		_updateEnergy( );

public:
/* Functions */
	ClapTrap( );
	ClapTrap( std::string name );
	ClapTrap( ClapTrap const & src );

	~ClapTrap( );
	
	ClapTrap &	operator=( ClapTrap const & rhs );

	
	std::string	getName( ) const;
	uint		getHP( ) const;
	uint		getEP( ) const;
	uint		getAD( ) const;
	void		attack( std::string& target );
	void		takeDamage( uint damage );
	void		beRepaired( uint damage );

};

std::ostream & operator<<( std::ostream & o, ClapTrap const & s );

#endif // CLAPTRAP_HPP_
