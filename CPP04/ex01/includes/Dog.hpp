#ifndef DOG_HPP_
# define DOG_HPP_

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Dog : public Animal {

private:
	Brain	*_brain;

public:
/* Functions */
	Dog( );
	~Dog( );
	Dog( Dog const & src );
	Dog &	operator=( Dog const & rhs );

	virtual void	makeSound( ) const;

	// Child implementation of base class's virtual function
	virtual void	spewIdea( ) const;

};

#endif // DOG_HPP_
