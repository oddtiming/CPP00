#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <cstdlib>
// #include <cmath>

using std::list;
using std::vector;
using std::string;
using std::cout;
using std::endl;
long long getTimeInNanoseconds( );

namespace test {
	void displayInt(int i) {
		cout << i << endl;
	}
}

int	main() {
	srand( static_cast<uint>(getTimeInNanoseconds()) );
	
	list<int>	lst;
	int			n;

	cout << "list:\t{ ";
	for (int i = 0; i < 10; i++) {
		n = rand() % 100;
		cout << n << " ";
		lst.push_back(n);
	}
	cout << "}"  <<  endl;

	vector<int>	diff(lst.size());

	std::adjacent_difference(lst.begin(), lst.end(), diff.begin());

	cout << "diff:\t{  ";

	vector<int>::iterator it;
	vector<int>::iterator ite = diff.end();

	for (it = diff.begin(); it != ite; ++it) {
		cout << *it << " ";
	}


	// for (int i = 0; i < 10; i++) {
	// 	cout << " " << diff[i];
	// }

	cout << "}"  <<  endl;


	// for_each(lst.begin(), lst.end(), test::displayInt);

	return 0;
}
