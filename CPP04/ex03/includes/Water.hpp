#include "MateriaSource.hpp"
#include <iostream>
#include <string>

class Water : virtual public MateriaSource
{
	private:
		std::string	_name;
	
	public:

		Water( );
		Water( Water const & src );
		Water &	operator=( Water const & rhs );

		~Water( );

		void use(Water& target);
};
