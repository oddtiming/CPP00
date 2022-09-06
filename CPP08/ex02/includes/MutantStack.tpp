#ifndef CPP08_02_MUTANT_STACK_HPP_
# define CPP08_02_MUTANT_STACK_HPP_

# include <iostream>
# include <deque>
# include <stack>

// https://stackoverflow.com/questions/525365/
template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

private:
public:
	/* Ctors/dtor */
	MutantStack( ) { }
	MutantStack( std::stack< T, Container > s) : 
		std::stack<T, Container>( s ) {  }
	MutantStack( MutantStack const & src ) :
		std::stack<T, Container>( src.c ) { }
	~MutantStack( ) { }

	/* Assignment operators */
	MutantStack &	operator=( MutantStack const & rhs ) { 
		this->c = rhs.c;
		
		return *this;
	}

	using std::stack<T, Container>::c;

	// QoL typedef
	typedef typename std::stack<T, Container>::container_type::iterator		iterator;

    // expose iterators of the underlying container
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

    // expose const iterators of the underlying container
	iterator begin() const { return this->c.begin(); }
	iterator end() const { return this->c.end(); }

};

#endif // CPP08_02_MUTANT_STACK_HPP_
