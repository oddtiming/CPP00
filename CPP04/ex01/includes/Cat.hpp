#ifndef CAT_HPP_
# define CAT_HPP_

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Cat : public Animal {

private:
	Brain	*_brain;

public:
/* Functions */
	Cat( );
	~Cat( );
	Cat( Cat const & src );
	Cat &	operator=( Cat const & rhs );

	virtual void	makeSound( ) const;

	// Child implementation of base class's virtual function
	virtual void	spewIdea( ) const;

};

#endif // CAT_HPP_
 