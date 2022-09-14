#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <list>
#include "MutantStack.tpp"
#include "tests.tpp"

#define NB_VALS 10000

void    test_lists();
void    test_deques();
void    test_vectors();
void    test_copies();

int	main( ) {

	test_lists();
	test_deques();
	test_vectors();
	test_copies();
}
