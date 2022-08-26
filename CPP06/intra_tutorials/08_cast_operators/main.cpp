#include <iostream>

// typecast operators in CPP allow you to declare
// specific overloads to do implicit conversion towards certain types


class Foo
{

	private:
		float	_v;

	public:

		Foo( float const v ) : _v( v ) { }

		float getV()		{ return this->_v; }

		operator float()	{ return this->_v; }
		operator int()		{ return static_cast<int>(this->_v); }

};

int	main( ) {

	Foo		a( 42.942f );	

	float	b = a;			// Implicit cast --> OK
	int		c = a;			// Implicit cast --> OK


	std::cout << a.getV() << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;


	try {	int e	= static_cast<int>(a);
		std::cout << "static_cast<int>(a) worked!" << std::endl; } catch(std::bad_cast & e) {
		std::cout << "static_cast<int>(a) didn't work: " << e.what() << std::endl; }

	try {	float e	= static_cast<float>(a);
		std::cout << "static_cast<float>(a) worked!" << std::endl; } catch(std::bad_cast & e) {
		std::cout << "static_cast<float>(a) didn't work: " << e.what() << std::endl; }

	// does not work, even if you give a definition
	// int * e	= static_cast<int*>(&a);

	
	return 0;
}
