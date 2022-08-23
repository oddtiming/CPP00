#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main( ) {

	const Animal *	array[20];

	for (int i = 0; i < 10; i++) {

		array[i] = new Cat();
		( (Cat *)array[i] )->Cat::spewIdea();
	}

	for (int i = 10; i < 20; i++) {

		array[i] = new Dog();
		( (Dog *)array[i] )->Dog::spewIdea();
	}

	for (int i = 0; i < 20; i++)
		delete array[i];
	
	return 0;
}
