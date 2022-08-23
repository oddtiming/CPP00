#ifndef MATERIA_SOURCE_HPP_
# define MATERIA_SOURCE_HPP_

# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include <iostream>
# include <string>

# define NB_MATERIA 4
class MateriaSource  : virtual public IMateriaSource
{
	private:
		AMateria *	_library[NB_MATERIA];
		uint		_nbItems;
	
	public:
		MateriaSource( );
		MateriaSource( MateriaSource const & src );
		MateriaSource &	operator=( MateriaSource const & rhs );
		~MateriaSource( );

		/* IMateriaSource member fct implementations */
		void			learnMateria( AMateria* src );
		AMateria *		createMateria( std::string const & type );
		
		/* Getter/setter */
		uint			getNbItems( ) const;
		AMateria *		getLibraryItem( uint index ) const;
		
};

#endif // MATERIA_SOURCE_HPP_