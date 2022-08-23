#ifndef WRONG_ANIMAL_HPP_
# define WRONG_ANIMAL_HPP_

# include <iostream>
# include <string>

class WrongAnimal {

protected:
/* Attributes */
	std::string	_type;

public:
/* Functions */
	WrongAnimal( );
	WrongAnimal( std::string name );
	WrongAnimal( WrongAnimal const & src );

	WrongAnimal &	operator=( WrongAnimal const & rhs );

	virtual ~WrongAnimal( );

	virtual void	makeSound( ) const;
	std::string		getType( ) const;

};

std::ostream & operator<<( std::ostream & o, WrongAnimal const & s );

#endif // WRONG_ANIMAL_HPP_
