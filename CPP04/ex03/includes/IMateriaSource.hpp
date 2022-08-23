#ifndef I_MATERIA_SOURCE_HPP_
# define I_MATERIA_SOURCE_HPP_

#include "AMateria.hpp"
# include <iostream>
# include <string>

class IMateriaSource
{
	public:		
		virtual ~IMateriaSource() { }

		// Member functions
		// Need to be implemented by subclass
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif // I_MATERIA_SOURCE_HPP_