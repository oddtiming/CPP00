#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

# include <string>
# include <iostream>

class Zombie {

private:
	/* Attributes */
	std::string	_name;
	
public:
	Zombie( std::string name );
	~Zombie( void );

	/* Functions */
	void		announce( void ) const;
	std::string	const & getName( void ) const;

};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif // ZOMBIE_HPP_
