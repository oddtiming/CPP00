#ifndef WEAPON_HPP_
# define WEAPON_HPP_

# include <string>

class Weapon {

private:
/* Attributes */
	std::string	_type;

public:
/* Functions */
	Weapon( std::string );
	~Weapon( void );
	std::string getType( void );
	void		setType( std::string type );

};

#endif // WEAPON_HPP_
