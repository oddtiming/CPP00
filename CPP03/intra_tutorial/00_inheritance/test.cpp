// https://discuss.geeksforgeeks.org/comment/4249999252

#include <iostream>
using namespace std;

class A
{
		int _x;
	public:
		A(int i) { _x = i; cout << "A created" << endl; }
		int	getX() { return this->_x; }
};

class B: virtual public A
{
	public:
		B() : A(10) { cout << "B created" << endl; }
};

class C: virtual public A
{
	public:
		C( ) : A(10) { cout << "C created" << endl; }
};

class D: public B, public C
{
	private:
		int _x;
	public:
		D(int i) : B(), C(), A(10), _x(i) { cout << "D created" << endl; }
		D( ) 	 : B(), C(), A(10), _x(0) { cout << "D created" << endl; }
		int	getX() { return this->_x; }
};

int main()
{
	D d( 3 );
	cout << "d.getX() = " << d.getX() << endl;
	cout << "d.A::getX() = " << d.A::getX() << endl;
	return 0;
}
