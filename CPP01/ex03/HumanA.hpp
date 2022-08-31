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
	/* Ctors/dtors */
	HumanA( std::string name, Weapon& weapon );
	~HumanA( void );
	
	/* Member functions */
	void	attack( void ) const;

};

#endif // HUMANA_HPP_
