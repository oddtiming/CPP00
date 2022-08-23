#ifndef WRONG_CAT_HPP_
# define WRONG_CAT_HPP_

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>

class WrongCat : public WrongAnimal {

public:
/* Functions */
	WrongCat( );
	~WrongCat( );
	WrongCat( WrongCat const & src );
	WrongCat &	operator=( WrongCat const & rhs );

	virtual void		makeSound( ) const;

	std::string	getType( ) const;

};

std::ostream & operator<<( std::ostream & o, WrongCat const & s );

#endif // WRONG_CAT_HPP_
