#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

Span::Span( ) : _N(0), _vec() {	return ; }

Span::Span( int const & N ) : _N(N), _vec() { return ; }

Span::Span( Span const & src ) : _N(src._N), _vec(src._vec) { return ; }

Span &	Span::operator=( Span const & rhs ) {
	(void)rhs;
	return *this;
}

Span::~Span( ) { return ; }

/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/

void	Span::addNumber( int i ) {
	this->_vec.push_back(i);
}

void	Span::fill( int N ) {
	for (int i = 0; i < N; i++)
		this->_vec.push_back(i * 10);
}


uint	Span::longestSpan( ) {

	std::vector<int>::iterator	itmax = std::max_element(_vec.begin(), _vec.end());
	std::vector<int>::iterator	itmin = std::min_element(_vec.begin(), _vec.end());

	return abs(*itmax - *itmin);
}

uint	Span::longestSpanAdjacent( ) {
	std::vector<int>	diffs(_vec.size());
	
	std::adjacent_difference(this->_vec.begin(), this->_vec.end(), diffs.begin());
	std::sort(diffs.begin(), diffs.end());

	return (-diffs.front() > diffs.back() ? -diffs.front() : diffs.back());
}

// to satisfy for_each loops
static void toAbs(int & i) { i = (i < 0 ? -i : i ); }

uint	Span::shortestSpan( ) {
	std::vector<int>	diffs = _vec;
	
	std::sort(diffs.begin(), diffs.end());
	std::adjacent_difference(diffs.begin(), diffs.end(), diffs.begin());
	std::for_each(diffs.begin(), diffs.end(), toAbs);
	
	return *(std::min_element(++diffs.begin(), diffs.end() ) );
}


uint	Span::shortestSpanAdjacent( ) {
	std::vector<int>	diffs(_vec.size());
	
	std::adjacent_difference(this->_vec.begin(), this->_vec.end(), diffs.begin());
	std::for_each(diffs.begin(), diffs.end(), toAbs);

	return *(std::min_element(++diffs.begin(), diffs.end() ) );
}

