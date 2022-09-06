#ifndef CPP08_02_MUTANT_STACK_HPP_
# define CPP08_02_MUTANT_STACK_HPP_

# include <iostream>
# include <deque>
# include <stack>

// https://stackoverflow.com/questions/525365/
template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

private:
	MutantStack( MutantStack const & src ) { return std::stack<T, Container>(src); }
public:
	/* Ctors/dtor */
	MutantStack( ) { }
	// MutantStack( std::stack< T, Container > s) : 
	// 	std::stack<T, Container>( s ) {  }
	~MutantStack( ) { }

	/* Assignment operators */
	// MutantStack &	operator=( MutantStack const & rhs ) { 
	// 	*this = MutantStack(std::stack<T, Container>(rhs));
		
	// 	return this->std::stack< T, Container >::operator=( rhs );
	// }

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
