#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

# include "ICharacter.hpp"
# include "MateriaSource.hpp"
# include <iostream>
# include <string>

# define NB_INVENTORY_SLOTS 4

class Character : virtual public ICharacter
{
	
	private:
		std::string		_name;
		AMateria *		_inventory[NB_INVENTORY_SLOTS];
		AMateria *		_droppedItems[32];
		uint			_nbItems;
		uint			_nbDroppedItems;
		uint			_droppedItemsCapacity;

	public:
		// Constructors
		Character( );
		Character( Character const & src );
		Character( std::string const & name );

		// Assignment operator
		Character &	operator=( Character const & rhs );

		// Destructor
		~Character( );

		std::string const & getName( ) const;
		
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

std::ostream & operator<<( std::ostream & o, Character const & s );

#endif // CHARACTER_HPP_
