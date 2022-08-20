#ifndef HUMANB_HPP_
# define HUMANB_HPP_

# include <string>
# include "Weapon.hpp"

class HumanB {

private:
/* Attributes */
	std::string	_name;
	Weapon*		_weapon;

public:
/* Functions */
	HumanB( std::string	name );
	~HumanB( void );
	void	setWeapon( Weapon& weapon );
	void	attack( void );

};

#endif // HUMANB_HPP_
