#include <iostream>
#include <ios>
#include <cstdint>

struct Data {
	int	val;
};

Data* deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }
uintptr_t serialize(Data* ptr) { return reinterpret_cast<uintptr_t>(ptr); }


using std::cout;
using std::endl;

int main(void)
{
	Data		*ptr = new Data;
	uintptr_t	raw;
	std::ios	iosCopy(NULL);

	iosCopy.copyfmt(cout);
	
	ptr->val = 1;
	cout << "Variable `ptr' has been allocated. Struct member val initialized to 1" << endl;
	cout << "ptr: " << std::hex << ptr << endl;
	cout.copyfmt(iosCopy);
	cout << "ptr->val: " << ptr->val << endl;

	ptr->val = 5;
	cout << "assigning 42 to struct member `val'" << endl;
	cout.copyfmt(iosCopy);
	cout << "ptr->val: " << ptr->val << endl;
	
	raw = serialize(ptr);
	cout << "raw = serialize(ptr) " << endl;
	cout << "raw: " << std::hex << raw << endl;


	cout << "Assigning ptr to NULL" << endl;
	ptr = NULL;

	cout << "ptr: " << std::hex << ptr << endl;
	cout << "raw: " << raw << endl;

	ptr = deserialize(raw);
	cout << "ptr = deserialize(raw)";
	cout << "ptr: " << std::hex << ptr << endl;
	cout.copyfmt(iosCopy);
	cout << "ptr->val: " << ptr->val << endl;

	delete ptr;


	return 0;
}
