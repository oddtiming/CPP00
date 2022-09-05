#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

# include "ICharacter.hpp"
# include "MateriaSource.hpp"
# include "StorageObject.hpp"
# include <iostream>
# include <string>

# define INVENTORY_MAX 4
# define DROPPED_MAX 4096

class Character : virtual public ICharacter
{
	private:
		std::string		_name;
		uint			_nbItems;
		AMateria *		_inventory[INVENTORY_MAX];
		uint			_nbStorages;
		StorageObject*	_droppedItems;

	public:
		// Constructors
		Character( );
		Character( Character const & src );
		Character( std::string const & name );

		// Assignment operator
		Character &	operator=( Character const & rhs );

		// Destructor
		virtual ~Character( );

		std::string const & getName( ) const;
		

		// Apparently child implementations need not be virtual
		//https://docs.microsoft.com/en-us/cpp/cpp/virtual-functions?view=msvc-170
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

std::ostream & operator<<( std::ostream & o, ICharacter const & s );

#endif // CHARACTER_HPP_
