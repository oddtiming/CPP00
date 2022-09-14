#include <iostream> // cout, endl
#include <iomanip>  // setw, setfill


void _print_table_border( size_t len, char c ) {
	std::cout << std::setw(len) << std::setfill(c) << c;
    std::cout << std::setfill(' ') << std::endl;
}

void _print_table_footer( size_t len ) {
    for (size_t i = 0; i < len; i++) {
        std::cout << "‾";
    }
    std::cout << std::endl;

}

void	_print_header( std::string const & text ) {
	uint len = text.length();
	
	std::cout << "\n" << std::setw(len * 3 + 5) << std::setfill('*') << "*" << std::endl;
	std::cout << std::setw(len + 2) << std::setfill(' ') << std::right << "* " << text << " *" << "\n";
	std::cout << std::setw(len * 3 + 5) << std::setfill('*') << "*" << std::endl;
}

#include <iostream>	// cout, endl
#include <cstdlib>	// rand(), srand()
#include <chrono>	// std::chrono::seconds, std::chrono::steady_clock::time_point, chrono::high_resolution_clock:

// https://www.codegrepper.com/code-examples/cpp/c%2B%2B+time+nanoseconds
long long getTimeInNanoseconds( ) {

	typedef std::chrono::high_resolution_clock		t_clock;
	typedef std::chrono::steady_clock::time_point	time_point;
	
	// ran once to initialize a seed time
    static time_point	start = t_clock::now();

    time_point			finish = t_clock::now();

	// convert to nanoseconds
	return (std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count());

}

uint	_random_gen( ) {
	
	srand( static_cast<uint>(getTimeInNanoseconds()) );
	
	return (rand());
}
