#ifndef CPP08_01_SPAN_HPP_
# define CPP08_01_SPAN_HPP_

# include <iostream>
# include <vector>
class SpanFullException : public std::exception {
	public:
		virtual const char* what() const throw() { return "SpanFullException"; }
};

class SpanEmptyException : public std::exception {
	public:
		virtual const char* what() const throw() { return "SpanEmptyException"; }
};


class Span {

private:
/* Attributes */
	uint const			_N;
	std::vector<int>	_vec;
	// cannot be used
	Span &	operator=( Span const & rhs );

public:
/* Functions */
	Span( );
	Span( int const & N );
	Span( Span const & src );

	
	~Span( );

	
	void	addNumber( int i );
	void	fill( int N );

	uint	longestSpan( );
	uint	shortestSpan( );

	uint	shortestSpanAdjacent( );
	uint	longestSpanAdjacent( );

};

std::ostream & operator<<( std::ostream & o, Span const & s );

#endif // CPP08_01_SPAN_HPP_
