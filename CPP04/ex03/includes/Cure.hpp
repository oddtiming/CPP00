#ifndef CURE_HPP_
# define CURE_HPP_

#include "AMateria.hpp"
#include <iostream>
#include <string>

class Cure : public AMateria
{
	public:

		Cure( );
		Cure( Cure const & src );
		Cure &	operator=( Cure const & rhs );

		~Cure( );

		virtual AMateria* clone() const;
		void use( ICharacter & target );
};

#endif // CURE_HPP_