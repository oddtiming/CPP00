#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <string>

class Character : virtual public ICharacter
{
	
	private:
		std::string	_name;

	public:
		Character( );
		Character( Character const & src );
		Character &	operator=( Character const & rhs );


		std::string const & getName() const;
		
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
