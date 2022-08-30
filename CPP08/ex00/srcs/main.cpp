#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "easyfind.tpp"

void	list_tests();
void	vector_tests();
void	deque_tests();
void	queue_tests();
void	stack_tests();


int	main( ) {

	list_tests();
	vector_tests();
	deque_tests();
	queue_tests();
	stack_tests();

	return 0;
}

