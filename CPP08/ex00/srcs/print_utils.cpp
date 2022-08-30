#include "tests.tpp"// for define of NB_VALS
#include <iostream>	// cout, endl
#include <iomanip>	// setw(), setfill()


void	_print_header( std::string const & text ) {
	std::cout << "\n" << std::setw(33) << std::setfill('*') << "\n";
	std::cout << "\t* " << text << " *" << "\n";
	std::cout << std::setw(33) << std::setfill('*') << "\n" << std::endl;
}

void 	_print_table_top ( ) {
	for (int i = 0; i < NB_VALS; i++)
		std::cout << "___";
	std::cout << std::endl << "|";
}


void 	_print_table_bot ( ) {
	for (int i = 0; i < NB_VALS; i++) 
		std::cout << "‾‾‾";
	std::cout << std::endl;
}


void 	_print_table_indices ( uint const & width ) {
	
	for (int i = 0 ; i < NB_VALS; i++) {
		std::cout << std::setw(width) << std::setfill(' ') << i << "|";
	}
	std::cout << ": Index" << std::endl << "|";

}
