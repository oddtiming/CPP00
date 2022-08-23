#ifndef A_MATERIA_HPP_
# define A_MATERIA_HPP_

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class ICharacter;
class AMateria {

	protected:
	/* Attributes */
		// To be implemented by subclass
		std::string	_type;
		std::string	_message;

	public:
	/* Functions */
		AMateria( ) { }
		AMateria( AMateria const & src );
		AMateria &	operator=( AMateria const & rhs );

		virtual ~AMateria( ) { }
		AMateria(std::string const & type);

		// Member functions
		std::string const & getType() const;	// Returns the materia type
		std::string const & getMessage() const;	// Returns the materia use message
		virtual void use( ICharacter& target );	// Prints _type+_message+target
		
		// To be implemented by subclass
		virtual AMateria* clone() const = 0;
};

std::ostream & operator<<( std::ostream & o, AMateria const & s );

#endif // A_MATERIA_HPP_
