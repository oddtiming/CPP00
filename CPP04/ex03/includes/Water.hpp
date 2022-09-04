#ifndef WATER_HPP_
# define WATER_HPP_

# include "AMateria.hpp"
# include <iostream>
# include <string>

class Water : public AMateria
{
	private:
		/* Since it apparently doesn't make sense to copy the type..? */
		Water( Water const & src );
		Water &	operator=( Water const & rhs );

	public:
		Water( );

		~Water( );

		virtual AMateria* clone() const;
		// void use( ICharacter & target );
};

#endif // WATER_HPP_