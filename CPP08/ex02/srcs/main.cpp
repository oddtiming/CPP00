#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include "MutantStack.tpp"

#define NB_VALS 10000

uint	_random_gen( );

int	main( ) {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	
	std::cout << "after mstack.pop() : ";
	std::cout << " mstack.top() : " << mstack.top() << std::endl;
	std::cout << " mstack.size() : " << mstack.size() << std::endl;
	// mstack.push(3);
	// mstack.push(5);
	// mstack.push(737);



	int temp;

	for (int i = 0; i < 10; i++ ) {
		// Try and standardize the outputs to be readable
		temp = _random_gen() % 1000;
		std::cout << "inserting: " << temp << std::endl;
		mstack.push( temp );
	}

	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;

	while (it != ite) {
	    std::cout << *it << std::endl;
		++it;
	}


	std::cout << "\n\n\t *** PART 2 *** \n" << std::endl;

	// MutantStack<int> mstack2 = mstack;
	MutantStack<int> mstack2;
	mstack2 = mstack;

	it = mstack2.begin();
	ite = mstack2.end();

	while (it != ite) {
	    std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	return 0;

}

#include <iostream>	// cout, endl
#include <cstdlib>	// rand(), srand()
#include <chrono>	// std::chrono::seconds, std::chrono::steady_clock::time_point, chrono::high_resolution_clock:

// https://www.codegrepper.com/code-examples/cpp/c%2B%2B+time+nanoseconds
long long getTimeInNanoseconds( ) {

	typedef std::chrono::high_resolution_clock		t_clock;
	typedef std::chrono::steady_clock::time_point	time_point;
	
	// ran once to initialize a seed time
    static time_point	start = t_clock::now();

    time_point			finish = t_clock::now();

	// convert to nanoseconds
	return (std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count());

}

uint	_random_gen( ) {
	
	srand( static_cast<uint>(getTimeInNanoseconds()) );
	
	return (rand());
}
