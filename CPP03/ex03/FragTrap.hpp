#ifndef FRAGTRAP_HPP_
# define FRAGTRAP_HPP_

# include <string>
# include <iostream>
# include <iomanip>
# include "ClapTrap.hpp"

# define FRAG_HP 100
# define FRAG_EP 100
# define FRAG_AD 30

class FragTrap : virtual public ClapTrap {

public:
/* Ctors/Dtors */
	FragTrap( );
	FragTrap( std::string name );
	FragTrap( FragTrap const & src );

	~FragTrap( );

	FragTrap &	operator=( FragTrap const & rhs );	
	
/* New member function */
	void		highFivesGuys( );	// does nothing but print a log msg to stdout

};

std::ostream & operator<<( std::ostream & o, FragTrap const & s );

#endif // FRAGTRAP_HPP_
