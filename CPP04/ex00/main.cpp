#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main( ) {

	const Animal*	meta = new Animal();
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();
	
	std::cout << "meta->getType(): " << meta->getType() << std::endl;
	std::cout << "cat->getType(): " << cat->getType() << std::endl;
	std::cout << "dog->getType(): " << dog->getType() << std::endl;
	cat->makeSound();			// will output Cat::makeSound()
	dog->makeSound();			// will output Dog::makeSound()
    meta->makeSound();			// will output Animal::makeSound()


	delete meta;
	delete cat;
	delete dog;


	const WrongAnimal*	wrongMeta = new WrongAnimal();
	const WrongAnimal*	wrongCat = new WrongCat();
	const WrongCat*		wrongCatCalled = new WrongCat();

	std::cout << "wrongMeta->getType(): "		<< wrongMeta->getType() << std::endl;
	std::cout << "wrongCat->getType(): "		<< wrongCat->getType() << std::endl;
	std::cout << "wrongCatCalled->getType(): "	<< wrongCat->getType() << std::endl;

    wrongMeta->makeSound();						// will output WrongAnimal::makeSound()
	wrongCat->makeSound();						// will output WrongAnimal::makeSound()
	static_cast< const WrongCat * >(wrongCat)->WrongCat::makeSound(); // will output WrongCat::makeSound()

	wrongCatCalled->makeSound();				// will output WrongCat::makeSound()
	wrongCatCalled->WrongCat::makeSound();		// will output WrongCat::makeSound()
	wrongCatCalled->WrongAnimal::makeSound();	// will output WrongAnimal::makeSound()


	delete wrongCat;
	delete wrongMeta;
	delete wrongCatCalled;


	return 0;
}
