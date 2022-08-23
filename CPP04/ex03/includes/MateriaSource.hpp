#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <iostream>
#include <string>

class MateriaSource  : public AMateria, virtual public IMateriaSource
{
	
	public:

		MateriaSource( );
		MateriaSource(std::string const & type);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
		MateriaSource* clone() const;
		virtual void use( MateriaSource& target );
};
