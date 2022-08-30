#ifndef CPP08_00_TESTS_TPP_
# define CPP08_00_TESTS_TPP_

# include "easyfind.tpp"
# include <iostream> // cout, endl

# include <iomanip>	// setw(), setfill()

/****************************/
/*		Test Parameters		*/
/****************************/
# define NB_TESTS	20
# define RANGE		30
# define NB_VALS	30


// utils.cpp
uint			_random_gen( );
int				nbDigits(long number);

// print_utils.cpp
void 	_print_table_top( );
void 	_print_table_bot( );
void 	_print_table_indices( uint const & width );

template <typename T>
void	_test_easyfind(T & p) {

	for (int i = 0; i < NB_TESTS; i++) {
		try {
			easyfind(p, _random_gen( ) % RANGE);
		} catch (IntNotFoundException & e) { 
			std::cerr << e.what() << std::endl;
			}
	}	
}

//  for vector, list, deque
template < typename T >
void	_generate_tests( T &					p, 
						 typename T::iterator	it,
						 typename T::iterator	ite) {
	static uint const	width = nbDigits(RANGE) ;
							 
							 
	_print_table_top();
	_print_table_indices( width );

	for( ; it != ite; it++) {
		*it = _random_gen() % RANGE ;
		std::cout << std::setw(2) << *it << "|";
	}
	std::cout << ": Value" << std::endl;
	
	_print_table_bot();
	
	_test_easyfind(p);
}
	


// Only for queue... :(
template <typename T>
void	_generate_tests( T & p ) {
	static uint const	width = nbDigits(RANGE) ;
	int					i = 0;
	int					rand_val;
							 
	_print_table_top();
	_print_table_indices( width );

	for(i = 0; i < NB_VALS; i++) {
		// b/c stack has top() and queue has back(), assign value to print
		rand_val = _random_gen() % RANGE;
		p.push( rand_val );
		std::cout << std::setw(2) << std::setfill(' ') << rand_val << "|";
	}
	std::cout << ": Value" << std::endl;
	
	_print_table_bot();

	_test_easyfind( p );

}

#endif // CPP08_00_TESTS_TPP_