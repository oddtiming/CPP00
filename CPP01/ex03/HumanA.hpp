#ifndef HUMANA_HPP_
# define HUMANA_HPP_

# include <string>
# include "Weapon.hpp"

class HumanA {

private:
/* Attributes */
	std::string	_name;
	Weapon&		_weapon;

public:
/* Functions */
	HumanA( std::string name, Weapon& weapon );
	~HumanA( void );
	void	attack( void );

};

#endif // HUMANA_HPP_
