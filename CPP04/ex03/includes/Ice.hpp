#include "MateriaSource.hpp"
#include <iostream>
#include <string>

class Ice : public MateriaSource
{
	private:
		std::string	_name;
	
	public:

		Ice( );
		Ice( Ice const & src );
		Ice &	operator=( Ice const & rhs );

		~Ice( );

		void use(Ice& target);
};
