#ifndef CAT_HPP_
# define CAT_HPP_

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Cat : public AAnimal {

private:
	Brain	*_brain;

public:
/* Functions */
	Cat( );
	Cat( Cat const & src );
	Cat &	operator=( Cat const & rhs );

	virtual ~Cat( );
	
	virtual void		makeSound( ) const;

	virtual void		spewIdea( ) const;

};

#endif // CAT_HPP_
