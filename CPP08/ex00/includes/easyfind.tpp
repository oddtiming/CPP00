#ifndef CPP_08_00_EASYFIND_TPP_
# define CPP_08_00_EASYFIND_TPP_

#include "easyfind.hpp"
#include <algorithm>
#include <deque>	// to convert Container Adaptors
#include <iostream>

// For list, vector, deque
template < typename T >
void	easyfind( T & p, int n) {
	uint	index = std::distance( p.begin(), std::find(p.begin(), p.end(), n));
	if (index == p.size())
		throw IntNotFoundException(n);
	std::cout << "Int "  << n << " was found at index " << index << std::endl;
}



// Little cheataroo for queues and stacks (Container Adaptors)
template <typename T>
class ContainerAdaptor : T {
public:
	ContainerAdaptor(T & q) : T(q) { } ;

	// returns a ref to subclass, but since `c' is protected,
	// we have to access it through a child class
	std::deque< int > &	get_subclass( ) { return this->c; } ;
};


// For queues and stacks
// This was not required, but I added it out of curiosity
template <template <class, class> class C, template <class, class> class Cont, class T >
void	easyfind(Cont<int, C< int, std::allocator<T> > > & p, int n) {

	if (p.empty())
		throw EmptyContainerException();

	ContainerAdaptor<Cont<int, std::deque< int, std::allocator<int> > > > q(p);
	easyfind(q.get_subclass(), n);

	return ;
}

#endif // CPP_08_00_EASYFIND_TPP_
