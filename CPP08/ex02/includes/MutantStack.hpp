#ifndef CPP08_02_MUTANT_STACK_HPP_
# define CPP08_02_MUTANT_STACK_HPP_

# include <iostream>
# include <deque>
# include <stack>

// https://stackoverflow.com/questions/525365/
template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

public:
/* Functions */
	MutantStack( ) { }
	~MutantStack( ) { }
	// MutantStack( MutantStack const & src ) { }
	// MutantStack &	operator=( MutantStack const & rhs ) { return *this; }

	using std::stack<T, Container>::c;

	// QoL typedef
	typedef typename std::stack<T, Container>::container_type::iterator
		iterator;

    // expose iterators of the underlying container
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

    // expose const iterators of the underlying container
	iterator begin() const { return this->c.begin(); }
	iterator end() const { return this->c.end(); }

};

#endif // CPP08_02_MUTANT_STACK_HPP_
