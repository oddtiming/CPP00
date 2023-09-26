#ifndef CLAPTRAP_HPP_
# define CLAPTRAP_HPP_

# include <string>
# include <iostream>

# define CLAP_HP 10
# define CLAP_EP 10
# define CLAP_AD 0

class ClapTrap {

private:
/* Attributes */
	std::string	_name;
	uint		_hitPts;
	uint		_energyPts;
	uint		_attackDmg;

/* Private member functions */
	void		_updateHealth( int change );	// damage is negative, repair is positive
	bool		_updateEnergy( );

public:
/* Ctors/Dtors */
	ClapTrap( );
	ClapTrap( ClapTrap const & src );
	ClapTrap( std::string name );
	~ClapTrap( );
	ClapTrap &	operator=( ClapTrap const & rhs );

/* Getters/setters */
	std::string	getName( ) const;
	uint		getHP( ) const;
	uint		getEP( ) const;
	uint		getAD( ) const;

/* Member functions */
	void		attack( std::string& target );
	void		takeDamage( uint damage );
	void		beRepaired( uint damage );

};

std::ostream & operator<<( std::ostream & o, ClapTrap const & s );

#endif // CLAPTRAP_HPP_
