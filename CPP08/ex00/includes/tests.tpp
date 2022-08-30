#ifndef CPP08_00_TESTS_TPP_
# define CPP08_00_TESTS_TPP_

# include "easyfind.tpp"
# include <iostream> // cout, endl

# include <iomanip>	// setw(), setfill()
# include <stdexcept>

/****************************/
/*		Test Parameters		*/
/****************************/
# define NB_TESTS	20
# define RANGE		30
# define NB_VALS	30


// utils.c
// long long		getTimeInNanoseconds( );
// void			_print_header( std::string const & text );
uint			_random_gen( );
static void 	_print_table_top( );
static void 	_print_table_bot( );
static void 	_print_table_indices( uint const & width );

int				nbDigits(long number);

// Template for vector, list, deque
template < template <class, class> class Cont, class T >
void	_generate_tests( Cont< int, std::allocator<T> > &			p, 
						 typename Cont< int, std::allocator<T> >::iterator	it,
						 typename Cont< int, std::allocator<T> >::iterator	ite) {
	static uint const	width = nbDigits(RANGE) ;
	int					i = 0;
							 
							 
	_print_table_top();
	_print_table_indices( width );

	// assign and print randomly generated values
	// for vector, list, deque
	for( ; it != ite; it++) {
		*it = _random_gen() % RANGE ;
		std::cout << std::setw(2) << *it << "|";
	}
	std::cout << ": Value" << std::endl;
	
	_print_table_bot();
	
	// easyfind
	for (i = 0; i < NB_TESTS; i++) {
		try {
			easyfind(p, _random_gen( ) % RANGE);
		} catch (IntNotFoundException & e) { 
			std::cerr << e.what() << std::endl;
			}
	}
}

template <typename T>
void	test_easyfind(T & p) {
	for (int i = 0; i < NB_TESTS; i++) {
		try {
			easyfind(p, _random_gen() % RANGE );
		} catch (IntNotFoundException & e) { 
			std::cerr << e.what() << std::endl;
		} catch (EmptyContainerException & e) { 
			std::cerr << e.what() << std::endl;
		}
	}
}


// Only for queue... :(
template <template <class, class> class C, template <class, class> class Cont, class T >
void	_generate_tests( Cont<int, C< int, std::allocator<T> > > & p ) {
	static uint const	width = nbDigits(RANGE) ;
	int					i = 0;
							 
	_print_table_top();
	_print_table_indices( width );

	// assign and print randomly generated values
	for(int i = 0; i < NB_VALS; i++) {
		p.push( _random_gen() % RANGE );
		std::cout << std::setw(2) << std::setfill(' ') << p.back() << "|";
	}
	std::cout << ": Value" << std::endl;
	

	_print_table_bot();

	// easyfind
	for (i = 0; i < NB_TESTS; i++) {
		try {
			easyfind(p, _random_gen() % RANGE );
		} catch (IntNotFoundException & e) { 
			std::cerr << e.what() << std::endl;
		} catch (EmptyContainerException & e) { 
			std::cerr << e.what() << std::endl;
		}
	}
}

static void 	_print_table_top ( ) {
	for (int i = 0; i < NB_VALS; i++)
		std::cout << "___";
	std::cout << std::endl << "|";
}


static void 	_print_table_bot ( ) {
	for (int i = 0; i < NB_VALS; i++) 
		std::cout << "‾‾‾";
	std::cout << std::endl;
}


static void 	_print_table_indices ( uint const & width ) {
	
	for (int i = 0 ; i < NB_VALS; i++) {
		std::cout << std::setw(width) << std::setfill(' ') << i << "|";
	}
	std::cout << ": Index" << std::endl << "|";

}


#endif // CPP08_00_TESTS_TPP_