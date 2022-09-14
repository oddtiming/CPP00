#include <list>
#include <vector>
#include <deque>
#include <stack>
#include <iostream>
#include "MutantStack.tpp"
#include "tests.tpp"

void	_print_header( std::string const & text );

void    test_lists() {
  	MutantStack<int>    mstack;
	std::list<int>	    cont;

	_print_header("List tests");
    _fill_data(mstack, cont);
	_print_tables(mstack, cont);
}

void    test_deques() {
  	MutantStack<int>    mstack;
	std::deque<int>	    cont;

	_print_header("Deque tests");
    _fill_data(mstack, cont);
	_print_tables(mstack, cont);
}

void    test_vectors() {
  	MutantStack<int>    mstack;
	std::vector<int>    cont;

	_print_header("Vector tests");
    _fill_data(mstack, cont);
	_print_tables(mstack, cont);
}

void    test_copies() {

	MutantStack<int> mstack2;

    _print_header("Part 2 : copy tests");

	{
        int              tmp;
		MutantStack<int> mstack;

		for (int i = 0; i < 10; i++ ) {
			tmp = _random_gen() % 1000;
			std::cout << "inserting: " << tmp << std::endl;
			mstack.push( tmp );
		}
        mstack2 = mstack;
	}

	MutantStack<int>::iterator   it = mstack2.begin();
	MutantStack<int>::iterator   ite = mstack2.end();

	while (it != ite) {
	    std::cout << *it << std::endl;
		++it;
	}

	return;
}
