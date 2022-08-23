#include "MateriaSource.hpp"
#include <iostream>
#include <string>

class Cure : virtual public MateriaSource
{
	private:
		std::string	_name;
	
	public:

		Cure( );
		Cure( Cure const & src );
		Cure &	operator=( Cure const & rhs );

		~Cure( );

		void use(Cure& target);
};
