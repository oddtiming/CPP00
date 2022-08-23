#ifndef CURE_HPP_
# define CURE_HPP_

#include "AMateria.hpp"
#include <iostream>
#include <string>

class Cure : virtual public AMateria
{
	private:
		std::string	_name;
	
	public:

		Cure( ) { }
		Cure( Cure const & src );
		Cure &	operator=( Cure const & rhs );

		~Cure( ) { }

		void use( ICharacter & target );
};

#endif // CURE_HPP_