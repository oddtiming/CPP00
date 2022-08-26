#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main( ) {

	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();
	
	std::cout << "cat->getType(): " << cat->getType() << std::endl;
	std::cout << "dog->getType(): " << dog->getType() << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();


	delete cat;
	delete dog;

	

	// Uncommenting the following lines will generate compiler error

	// const AAnimal* meta = new AAnimal();
    // meta->makeSound();
	// delete meta;

	return 0;
}
