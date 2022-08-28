#ifndef DOG_HPP_
# define DOG_HPP_

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Dog : public AAnimal {

private:
	Brain	*_brain;

public:
/* Functions */
	Dog( );
	Dog( Dog const & src );
	Dog &	operator=( Dog const & rhs );

	virtual ~Dog( );
	virtual void		makeSound( ) const;

	virtual void		spewIdea( ) const;

};

#endif // DOG_HPP_
