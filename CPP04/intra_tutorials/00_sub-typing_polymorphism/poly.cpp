#include <string>
#include <iostream>

class Character {

	public:
		// This makes the function known at compilation time
		// void sayHi(std::string const & target) { std::cout << "Character says hi to " << target << std::endl; }

		// This allows the function type to be resolved dynamically at execution time
		// These are called methods
		virtual void sayHi(std::string const & target) { std::cout << "Character says hi to " << target << std::endl; }
};

class Warrior : public Character {
	
	public:
		virtual void sayHi(std::string const & target) { std::cout << "Warrior says hi to " << target << std::endl; }
};

class Cat {
	// [...]
	public:
		void sayHi(std::string const & target) { std::cout << "Cat says hi to " << target << std::endl; }
};


int	main( ) {

	// This is fine, since a Warrior IS a Warrior
	Warrior	*w = new Warrior();
	
	// This is also fine, since a Warrior IS a Character
	Character	*c = new Warrior();

	// This is not fine, since a Character IS NOT a Warrior
	// (they are not even related)
	// Warrior	*w = new Character();

	// This is not fine, since a Character IS NOT a Warrior
	// (they are not even related)
	// Character*w = new Character();


	w->sayHi("test");
	c->sayHi("test");

	delete w;
	delete c;

	return 0;
}
