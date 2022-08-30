#ifndef EASYFIND_TPP_
# define EASYFIND_TPP_

#include "easyfind.hpp"
#include <algorithm>
#include <iterator>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>

// For all containers that recognize begin()
template < typename T >
void	easyfind( T & p, int n) {
	
	if ( p.empty() )
		throw EmptyContainerException();

	unsigned int	index; 
	
	index = std::distance( p.begin(), std::find(p.begin(), p.end(), n));

	if (index == p.size())
		throw IntNotFoundException(n);
	
	std::cout << "Int "  << n 
		<< " was found at index "
		<< index
		<< std::endl;
	return ;
}


// Little cheataroo for queues
// template <typename T>
// class Queue: T {
// public:
// 	Queue(T & q) : T(q) { } 
// 	Queue(std::queue & q) : T(q) { } 
// 	Queue(std::stack & q) : T(q) { } 
	
// 	std::deque<int, std::allocator<int> > &		get_subclass( ) const { return this->c; };
// };

template <typename T>
class Queue : T {
public:
	Queue(T & q) : T(q) { } ;
	
	std::deque< int > &	get_subclass( ) { return this->c; } ;
};


// class Queue : std::stack<int> {
// public:
// 	Queue(std::stack<int> & q) : std::stack<int>(q) { } ;
	
// 	std::deque< int > &	get_subclass( ) { return this->c; } ;
// };

template <template <class, class> class C, template <class, class> class Cont, class T >
void	easyfind(Cont<int, C< int, std::allocator<T> > > & p, int n) {

	if (p.empty())
		throw EmptyContainerException();

	Queue<Cont<int, std::deque< int, std::allocator<int> > > > q(p);
	easyfind(q.get_subclass(), n);

	return ;
}

#endif // EASYFIND_TPP_
