#ifndef DOG_HPP_
# define DOG_HPP_

# include "Animal.hpp"
# include <iostream>
# include <string>

class Dog : public Animal {

public:
/* Functions */
	Dog( );
	~Dog( );
	Dog( Dog const & src );
	Dog &	operator=( Dog const & rhs );

	virtual void		makeSound( ) const;

	std::string	getType( ) const;

};

std::ostream & operator<<( std::ostream & o, Dog const & s );

#endif // DOG_HPP_
