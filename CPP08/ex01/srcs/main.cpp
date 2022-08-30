#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "Span.hpp"

#define NB_VALS 10000

uint	_random_gen( );

int	main( ) {
	
	Span sp1 = Span(5);
	
	
	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);
	
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.shortestSpanAdjacent() << std::endl;
	
	std::cout << sp1.longestSpan() << std::endl;
	std::cout << sp1.longestSpanAdjacent() << std::endl;

	std::cout << std::endl;
	
	Span sp2 = Span(NB_VALS);
	
	sp2.addNumber(-1);		// shortest adjacent span -> 2
	sp2.addNumber(-3);		// longest adjacent span -> 20
	sp2.addNumber(17);
	sp2.addNumber(9);
	sp2.addNumber(-2);		// shortest span with -3 -> 1
	sp2.addNumber(-10);		// longest span with end of loop -> 10 * NB_VALS

	sp2.fill(NB_VALS);


	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.shortestSpanAdjacent() << std::endl;
	
	std::cout << sp2.longestSpan() << std::endl;
	std::cout << sp2.longestSpanAdjacent() << std::endl;


	return 0;
}

