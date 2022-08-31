#ifndef HUMANB_HPP_
# define HUMANB_HPP_

# include <string>
# include "Weapon.hpp"

class HumanB {

private:
	/* Attributes */
	std::string	_name;
	Weapon *	_weapon;

public:
	/* Dtors/ctors */
	HumanB( std::string	name );
	~HumanB( void );


	/* Member functions */
	void	setWeapon( Weapon & weapon );
	void	attack( void ) const;

};

#endif // HUMANB_HPP_
