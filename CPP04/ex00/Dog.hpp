#ifndef DOG_HPP_
# define DOG_HPP_

# include "Animal.hpp"
# include <iostream>
# include <string>

class Dog : public Animal {

public:
/* Functions */
	Dog( );
	Dog( Dog const & src );
	
	Dog &	operator=( Dog const & rhs );

	virtual ~Dog( );
	
	virtual void		makeSound( ) const;
};

#endif // DOG_HPP_
