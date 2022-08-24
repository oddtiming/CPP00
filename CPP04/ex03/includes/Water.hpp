#ifndef WATER_HPP_
# define WATER_HPP_

# include "AMateria.hpp"
# include <iostream>
# include <string>

class Water : public AMateria
{

	public:

		Water( );
		Water( Water const & src );
		Water &	operator=( Water const & rhs );

		~Water( );

		virtual AMateria* clone() const;
		// void use( ICharacter & target );
};

#endif // WATER_HPP_