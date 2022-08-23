#include "MateriaSource.hpp"
#include <iostream>
#include <string>

class Fire : virtual public MateriaSource
{
	private:
		std::string	_name;
	
	public:

		Fire( );
		Fire( Fire const & src );
		Fire &	operator=( Fire const & rhs );

		~Fire( );

		void use(Fire& target);
};
