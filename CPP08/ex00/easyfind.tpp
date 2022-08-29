#ifndef EASYFIND_TPP_
# define EASYFIND_TPP_

#include <algorithm>
#include "easyfind.hpp"
#include <iterator>
#include <iterator>
#include <string>
#include <cstring>

// https://stackoverflow.com/questions/18613770/stl-container-as-a-template-parameter
template < template < class > class Cont>
void	easyfind( Cont<int> & p, int i) {
	
	std::cout << "easyfind() w Cont<int> called" << std::endl;
	if ( p.empty() )
		throw EmptyContainerException();

	typename Cont< int >::iterator	it = p.begin();
	typename Cont< int >::iterator	ite = p.end();


	it = std::find(it, ite, i);

	if (it == ite)
		throw IntNotFoundException(i);
	
	std::cout << "Int "  << i 
		<< " was found at index "
		<< std::distance( p.begin(), it )
		<< std::endl;
	return ;
	
}

// https://stackoverflow.com/questions/18613770/stl-container-as-a-template-parameter
template < template <class, class> class Cont, class T >
void	easyfind( Cont< int, std::allocator<T> > & p, int i) {

	// std::cout << "easyfind() w Cont< int, std::allocator<T> > called" << std::endl;
	
	if (p.empty())
		throw EmptyContainerException();

	typename Cont< int, std::allocator<T> >::iterator	it = p.begin();
	typename Cont< int, std::allocator<T> >::iterator	ite = p.end();

	it = std::find(it, ite, i);

	if (it == ite)
		throw IntNotFoundException(i);
	
	std::cout << "Int "  << i 
		<< " was found at index "
		<< std::distance( p.begin(), it )
		<< std::endl;
	return ;
}

template <template <class, class> class C, template <class, class> class Cont, class T >
void	easyfind(Cont<int, C< int, std::allocator<T> > > & p, int i) {

	if (p.empty())
		throw EmptyContainerException();

	std::vector<int>	vec(p.size());

	for (size_t i = 0; i < p.size(); i++) {
		vec.push_back(p.front());
		p.pop();
	}


	easyfind(vec, i);


	// This doesn't work, 

	return ;
}

#endif // EASYFIND_TPP_
