#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main( ) {

	Animal *	array[20];

	for (int i = 0; i < 10; i++) {

		array[i] = new Cat();
		( (Cat *)array[i] )->Cat::spewIdea();
	}

	for (int i = 10; i < 20; i++) {

		array[i] = new Dog();
		( (Dog *)array[i] )->Dog::spewIdea();
	}


	// Showcases both copy constructor and copy assignment operator
	Cat catCopy1 = *(Cat *)array[0];
	Cat catCopy2;
	
	catCopy2 = *(Cat *)array[1];

	Dog dogCopy1 = *(Dog *)array[10];
	Dog dogCopy2;
	
	dogCopy2 = *(Dog *)array[11];

	for (int i = 0; i < 20; i++)
		delete array[i];
		

	// To show they still work after deletion of original objects
	catCopy1.makeSound();
	catCopy2.makeSound();

	dogCopy1.makeSound();
	dogCopy2.makeSound();


	return 0;
}
