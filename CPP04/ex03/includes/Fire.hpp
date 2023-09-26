#ifndef FIRE_HPP_
# define FIRE_HPP_

# include "AMateria.hpp"
# include <iostream>
# include <string>

class Fire : public AMateria
{
	private:
		/* Since it apparently doesn't make sense to copy the type..? */
		Fire( Fire const & src );
		Fire &	operator=( Fire const & rhs );

	public:
		Fire( );

		~Fire( );

		virtual AMateria* clone() const;
		void use( ICharacter & target );
};

#endif // FIRE_HPP_