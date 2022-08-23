#ifndef AMATERIA_HPP_
# define AMATERIA_HPP_

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class AMateria {

	protected:
	/* Attributes */
		std::string	_type;

	public:
	/* Functions */
		AMateria( );
		AMateria( AMateria const & src );
		AMateria &	operator=( AMateria const & rhs );

		virtual ~AMateria( );
		AMateria(std::string const & type);

		std::string const & getType() const; //Returns the materia type
		
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};


std::ostream & operator<<( std::ostream & o, AMateria const & s );

#endif // AMATERIA_HPP_
