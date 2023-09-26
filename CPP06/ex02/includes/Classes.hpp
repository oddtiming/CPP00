

class Base { 

public:
	virtual ~Base();
};


// Uncomment body to see traces
class A : public Base {

// public :
// 	A( ) { std::cout << "A()" << std::endl; }
};


class B : public Base {

// public :
// 	B( ) { std::cout << "B()" << std::endl; }
};


class C : public Base {

// public :
// 	C( ) { std::cout << "C()" << std::endl; }
};
