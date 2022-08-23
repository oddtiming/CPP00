#ifndef FIRE_HPP_
# define FIRE_HPP_

#include "AMateria.hpp"
#include <iostream>
#include <string>

class Fire : virtual public AMateria
{
	private:
		std::string	_name;
	
	public:

		Fire( ) { }
		Fire( Fire const & src );
		Fire &	operator=( Fire const & rhs );

		~Fire( ) { }

		void use( ICharacter & target );
};

#endif // FIRE_HPP_