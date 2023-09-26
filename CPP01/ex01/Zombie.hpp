#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

# include <string>
# include <iostream>

class Zombie {

private:
	/* Attributes */
	std::string	_name;
	
public:
	// Exposed a default constructor to allow new[] operator to work
	Zombie( void );
	Zombie( std::string name );
	~Zombie( void );

	/* Functions */
	void		announce( void ) const;
	std::string	const & getName( void ) const;
	void		setName( std::string );

};

Zombie*	zombieHorde( int N, std::string name );

#endif // ZOMBIE_HPP_
