#ifndef I_CHARACTER_HPP_
# define I_CHARACTER_HPP_

#include "AMateria.hpp"
#include <iostream>
# include <string>

class AMateria;

class ICharacter {

	public:
		virtual ~ICharacter() { }
		
		virtual std::string const & getName() const = 0;
		
		virtual void equip( AMateria * m) = 0;
		virtual void unequip( int idx ) = 0;
		virtual void use( int idx, ICharacter& target ) = 0;

};

std::ostream & operator<<( std::ostream & o, ICharacter const & s );

#endif // I_CHARACTER_HPP_