#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main( ) {

	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << "meta->getType(): " << meta->getType() << std::endl;
	std::cout << "cat->getType(): " << cat->getType() << std::endl;
	std::cout << "dog->getType(): " << dog->getType() << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
    meta->makeSound();


	delete meta;
	delete cat;
	delete dog;


	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "wrongMeta->getType(): " << wrongMeta->getType() << std::endl;
	std::cout << "wrongCat->getType(): " << wrongCat->getType() << std::endl;
    wrongMeta->makeSound();
	wrongCat->makeSound(); //will output the default sound!
	delete wrongCat;
	delete wrongMeta;


	return 0;
}
