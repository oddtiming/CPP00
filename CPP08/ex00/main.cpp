#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <list>
#include <vector>
#include <queue>
#include <queue>
#include <deque>
#include "easyfind.tpp"
// #include "easyfind.hpp"

using std::list;
using std::vector;
using std::deque;
using std::queue;
using std::string;
using std::cout;
using std::endl;
long long	getTimeInNanoseconds( );
void		_print_header( std::string const & text );


#define NB_TESTS	20
#define GEN_RANGE	30

uint _random_gen( ) {
	
	srand( static_cast<uint>(getTimeInNanoseconds()) );
	
	return (rand() % GEN_RANGE);
}

template < template <class, class> class Cont, class T >
void	_generate_tests( Cont< int, std::allocator<T> > &			p, 
						 typename Cont< int, std::allocator<T> >::iterator	it,
						 typename Cont< int, std::allocator<T> >::iterator	ite) {
	int	i = 0;
							 
	for (i = 0; i < GEN_RANGE; i++)
		std::cout << "___";
	std::cout << std::endl << "|";
	

	for (i = 0 ; i < GEN_RANGE; i++) {
		std::cout << std::setw(2) << std::setfill(' ') << i << "|";
	}
	std::cout << ": Index" << std::endl << "|";


	for( ; it != ite; it++) {
		*it = _random_gen();
		std::cout << std::setw(2) << *it << "|";
	}
	std::cout << ": Value" << std::endl;
	
	
	for (i = 0; i < GEN_RANGE; i++)
		std::cout << "‾‾‾";
	std::cout << std::endl;

	
	for (i = 0; i < NB_TESTS; i++) {
		try {
			easyfind(p, rand( ) % GEN_RANGE);
		}catch (IntNotFoundException & e) { 
			std::cerr << e.what() << std::endl;
			}
	}
}

void	generate_list_tests() {
	list<int>	p(GEN_RANGE);
	list<int>::iterator	it = p.begin();
	list<int>::iterator	ite = p.end();

	_print_header("List tests");

	_generate_tests(p, it, ite);
}

void	generate_vector_tests() {
	vector<int>	p(GEN_RANGE);
	vector<int>::iterator	it = p.begin();
	vector<int>::iterator	ite = p.end();

	_print_header("Vector tests");

	_generate_tests(p, it, ite);
}


void	generate_deque_tests() {
	deque<int>				p(GEN_RANGE);
	deque<int>::iterator	it = p.begin();
	deque<int>::iterator	ite = p.end();

	_print_header("Deques tests");

	_generate_tests(p, it, ite);
}

void	generate_queue_tests() {
	int						i;
	queue<int>				p;
	_print_header("Queue tests");
	
	for (i = 0; i < GEN_RANGE; i++)
		std::cout << "___";
	std::cout << std::endl << "|";
	
	for (i = 0 ; i < GEN_RANGE; i++) {
		std::cout << std::setw(2) << std::setfill(' ') << i << "|";
	}
	std::cout << ": Index" << std::endl << "|";

	for(int i = 0; i < GEN_RANGE; i++) {
		p.push( _random_gen() );
		std::cout << std::setw(2) << std::setfill(' ') << p.back() << "|";
	}
	std::cout << ": Value" << std::endl;
	
	for (i = 0; i < GEN_RANGE; i++)
		std::cout << "‾‾‾";
	std::cout << std::endl;

	for (i = 0; i < NB_TESTS; i++) {
		try {
			easyfind(p, rand( ) % GEN_RANGE);
		}catch (IntNotFoundException & e) { 
			std::cerr << e.what() << std::endl;
		} 
		
		catch (EmptyContainerException & e) { 
		
			// need to fix that shit
			std::cerr << e.what() << "Emptying queues will do that to ya..." << std::endl;
		}
	}
}


int	main( ) {

	generate_list_tests();
	generate_vector_tests();
	generate_deque_tests();
	generate_queue_tests();

	return 0;
}


#include <ctime>
#include <chrono>	 // std::chrono::seconds, std::chrono::steady_clock::time_point, chrono::high_resolution_clock:

typedef std::chrono::high_resolution_clock		t_clock;
typedef std::chrono::steady_clock::time_point	time_point;
// https://www.codegrepper.com/code-examples/cpp/c%2B%2B+time+nanoseconds
long long getTimeInNanoseconds( ) {

	// ran once initialize a seed time
    static time_point	start = t_clock::now();
    time_point			finish = t_clock::now();

	// convert to nanoseconds, prevent overflow
	return (std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() % UINT32_MAX);

}

void	_print_header( std::string const & text ) {
	std::cout << "\n" << std::setw(33) << std::setfill('*') << "\n";
	std::cout << "\t* " << text << " *" << "\n";
	std::cout << std::setw(33) << std::setfill('*') << "\n" << std::endl;
}
