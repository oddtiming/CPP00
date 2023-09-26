#ifndef WEAPON_HPP_
# define WEAPON_HPP_

# include <string>

class Weapon {

private:
	/* Attributes */
	std::string	_type;

public:
	/* Ctors/Dtors */
	Weapon( std::string );
	~Weapon( void );

	/* Member Functions */
	std::string const & 	getType( void ) const;
	void					setType( std::string type );

};

#endif // WEAPON_HPP_
