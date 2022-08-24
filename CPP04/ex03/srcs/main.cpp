#include <iostream>
#include "Cure.hpp"
#include "Fire.hpp"
#include "Ice.hpp"
#include "Water.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main( ) {

	/**
	 * 		Tests 
	 * 			learnMateria(): 
	 * 				- overflow error
	 * 
	 */
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Fire());
	src->learnMateria(new Water());
	src->learnMateria(new Water());

	/**
	 * 		Tests 
	 * 			createMateria():
	 * 				- multiple calls for same instance
	 * 				- unknown argument
	 * 				- empty argument
	 * 		 	equip():
	 * 				- overflow error
	 * 				- NULL argument
	 * 
	 */
	ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("fire");
    me->equip(tmp);
    tmp = src->createMateria("water");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("bleh");
    tmp = src->createMateria( "" );

	ICharacter* bob = new Character("bob");

	me->use( 0, *bob );
    me->use( 1, *bob );
    me->use( 2, *bob );
    me->use( 3, *bob );
	

	std::cout << std::endl;

	for (int i = 0; i < INVENTORY_MAX; i++)
		bob->equip( src->createMateria("fire") );

	bob->use( 2, *me );
	bob->use( 3, *bob );
	
	delete bob;
	delete me;


	/**
	 * 		Tests copy assignment operator
	 * 		(declaration as Character* allows it),
	 * 
	 */

	std::cout << "\n\n\tSECTION 2\n" << std::endl;

	Character* dude = new Character("dude McDude");
	Character* copy = new Character("copy");


    dude->equip( src->createMateria("ice") );
    dude->equip( src->createMateria("cure") );
    dude->equip( src->createMateria("fire") );
    dude->equip( src->createMateria("water") );

	// copy assignment operator
	*copy = *dude;

	// unequip() : checks for wrong index at size + 1
	for (int i = 0; i < INVENTORY_MAX + 1; i++)
		copy->unequip(i);

	copy->use(0, *dude );
    copy->equip( src->createMateria("ice") );
	copy->use(0, *dude );

	/**
	 * 		Tests use() after deletion in copy
	 * 			checks for shallow copy
	 */
	dude->use( 2, *copy );
	dude->use( 1, *copy );

	delete src;
	delete dude;
	delete copy;

	return 0;
}
