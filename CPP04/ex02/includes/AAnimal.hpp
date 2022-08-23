#ifndef ANIMAL_HPP_
# define ANIMAL_HPP_

# include <iostream>
# include <string>

class AAnimal {

protected:
/* Attributes */
	std::string	_type;

public:
/* Functions */
	AAnimal( );
	AAnimal( std::string name );
	AAnimal( AAnimal const & src );

	AAnimal &	operator=( AAnimal const & rhs );

	// Destructor needs to be virtual to allow calling objects 
	// to delete them before deleting themselves
	virtual ~AAnimal( );

	// Here it is crucial to NULL-initialize them !!!
	virtual void	makeSound( ) const = 0;
	virtual void	spewIdea( ) const = 0;
	std::string		getType( ) const;

};

std::ostream & operator<<( std::ostream & o, AAnimal const & s );

#endif // ANIMAL_HPP_
