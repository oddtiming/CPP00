#ifndef CURE_HPP_
# define CURE_HPP_

# include "AMateria.hpp"
# include <iostream>
# include <string>

class Cure : public AMateria
{
	private:
		/* Since it apparently doesn't make sense to copy the type..? */
		Cure( Cure const & src );
		Cure &	operator=( Cure const & rhs );

	public:
		Cure( );

		~Cure( );

		virtual AMateria* clone() const;
		void use( ICharacter & target );
};

#endif // CURE_HPP_