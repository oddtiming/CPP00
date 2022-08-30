#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "easyfind.tpp"

void	list_tests();
void	vector_tests();
void	deque_tests();
void	queue_tests();


int	main( ) {

	list_tests();
	vector_tests();
	deque_tests();
	queue_tests();

	return 0;
}

