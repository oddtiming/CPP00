#ifndef FIRE_HPP_
# define FIRE_HPP_

#include "AMateria.hpp"
#include <iostream>
#include <string>

class Fire : public AMateria
{	
	public:

		Fire( );
		Fire( Fire const & src );
		Fire &	operator=( Fire const & rhs );

		~Fire( );

		virtual AMateria* clone() const;
		void use( ICharacter & target );
};

#endif // FIRE_HPP_