#ifndef CAT_HPP_
# define CAT_HPP_

# include "Animal.hpp"
# include <iostream>
# include <string>

class Cat : public Animal {

public:
/* Functions */
	Cat( );
	~Cat( );
	Cat( Cat const & src );
	Cat &	operator=( Cat const & rhs );

	virtual void		makeSound( ) const;

	std::string	getType( ) const;

};

std::ostream & operator<<( std::ostream & o, Cat const & s );

#endif // CAT_HPP_