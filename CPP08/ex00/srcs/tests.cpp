#include "tests.tpp"

#include <list>
#include <vector>
#include <deque>

#include <queue>
#include <stack>

void	_print_header( std::string const & text );

void	list_tests() {
	std::list<int>				p(NB_VALS);
	std::list<int>::iterator	it = p.begin();
	std::list<int>::iterator	ite = p.end();

	_print_header("List tests");

	_generate_tests(p, it, ite);
}

void	vector_tests() {
	std::vector<int>			p(NB_VALS);
	std::vector<int>::iterator	it = p.begin();
	std::vector<int>::iterator	ite = p.end();

	_print_header("Vector tests");

	_generate_tests(p, it, ite);
}


void	deque_tests() {
	std::deque<int>				p(NB_VALS);
	std::deque<int>::iterator	it = p.begin();
	std::deque<int>::iterator	ite = p.end();

	_print_header("Deques tests");

	_generate_tests(p, it, ite);
}

void	queue_tests() {
	std::queue<int>				p;
	
	_print_header("Queue tests");

	_generate_tests(p);
	
}

