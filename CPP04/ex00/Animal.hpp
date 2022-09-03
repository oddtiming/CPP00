#ifndef ANIMAL_HPP_
# define ANIMAL_HPP_

# include <iostream>
# include <string>

class Animal {

protected:
/* Attributes */
	std::string	_type;   

public:
/* Functions */
	Animal( );
	Animal( std::string name );
	Animal( Animal const & src );

	Animal &	operator=( Animal const & rhs );

	// Destructor needs to be virtual to allow calling objects 
	// to delete them before deleting themselves
	virtual ~Animal( );

	virtual void			makeSound( ) const;
	std::string const &		getType( ) const;

};

std::ostream & operator<<( std::ostream & o, Animal const & s );

#endif // ANIMAL_HPP_
