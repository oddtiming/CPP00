#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

# include <string>
# include <iostream>

class Zombie {

private:
	/* Attributes */
	std::string	_name;
	
public:
	Zombie( void );
	Zombie( std::string name );
	~Zombie( void );

	/* Functions */
	void		announce( void );
	std::string	getName( void );
	void		setName( std::string );

};

Zombie*	zombieHorde( int N, std::string name );

#endif // ZOMBIE_HPP_
