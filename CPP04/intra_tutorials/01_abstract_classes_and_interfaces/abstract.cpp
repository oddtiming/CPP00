#include <string>
#include <iostream>


// A prefix to denote abstract class
class ACharacter {
	private:
		std::string	_name;
	
	public:

		// This says that a character must have an attack,
		// but a Character object doesn't have one itself
		virtual void attack( std::string const & target ) = 0;

		// This is instantiated by the class itself
		void sayHi(std::string const & target );
		std::string const& getName( ) { return this->_name; }
};

class Warrior : public ACharacter {
	public:
		virtual void attack( std::string const & target );

}; 

void ACharacter::sayHi( std::string const & target ) {
	std::cout << "ACharacter says Hi to " << target << std::endl;
}

void Warrior::attack( std::string const & target ) {
	std::cout << "Warrior atacks " << target << std::endl;
}

int	main( ) {

	// This is not fine, b/c AChar is purely virtual
	//ACharacter	*charA = new ACharacter();
	ACharacter*		w = new Warrior();

	w->attack( "Joe" );
	w->sayHi( "Bob" );


	return 0;
}
