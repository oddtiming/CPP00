#ifndef CAT_HPP_
# define CAT_HPP_

# include "Animal.hpp"
# include <iostream>
# include <string>

class Cat : public Animal {

public:
/* Functions */
	Cat( );
	Cat( Cat const & src );

	Cat &	operator=( Cat const & rhs );

	virtual ~Cat( );
	
	virtual void		makeSound( ) const;

};

#endif // CAT_HPP_
