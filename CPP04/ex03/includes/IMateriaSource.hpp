#ifndef I_MATERIA_SOURCE_HPP_
# define I_MATERIA_SOURCE_HPP_

#include "AMateria.hpp"
# include <iostream>
# include <string>

class IMateriaSource
{
	private:
	// Not sure it makes sense for an interface, nut better safe than sorry
		IMateriaSource( IMateriaSource const & src ) { (void)src; }
		IMateriaSource &	operator=( IMateriaSource const & rhs ) { 
			(void) rhs;
			return *this; }

	public:		
		IMateriaSource() { }
		virtual ~IMateriaSource() { }

		// Member functions
		// Need to be implemented by subclass
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif // I_MATERIA_SOURCE_HPP_