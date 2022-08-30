#ifndef CPP08_02_MUTANT_STACK_HPP_
# define CPP08_02_MUTANT_STACK_HPP_

# include <iostream>
# include <deque>
# include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

public:
/* Functions */
	MutantStack( ) { }
	~MutantStack( ) { }
	// MutantStack( MutantStack const & src ) { }
	// MutantStack &	operator=( MutantStack const & rhs ) { return *this; }

	typedef typename std::stack<T, Container>::container_type::iterator iterator;

    // expose just the iterators of the underlying container
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	iterator begin() const { return this->c.begin(); }
	iterator end() const { return this->c.end(); }

	

};

#endif // CPP08_02_MUTANT_STACK_HPP_
