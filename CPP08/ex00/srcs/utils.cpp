#include <iostream>	// cout, endl
#include <iomanip>	// setw(), setfill()
#include <cstdlib> // rand(), srand()
#include <string>
long long	getTimeInNanoseconds( );

void	_print_header( std::string const & text ) {
	std::cout << "\n" << std::setw(33) << std::setfill('*') << "\n";
	std::cout << "\t* " << text << " *" << "\n";
	std::cout << std::setw(33) << std::setfill('*') << "\n" << std::endl;
}

uint	_random_gen( ) {
	
	srand( static_cast<uint>(getTimeInNanoseconds()) );
	
	return (rand());
}

int		nbDigits(long number) {
    int digits = 0;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

// #include <ctime>
#include <chrono>	 // std::chrono::seconds, std::chrono::steady_clock::time_point, chrono::high_resolution_clock:

// https://www.codegrepper.com/code-examples/cpp/c%2B%2B+time+nanoseconds
long long getTimeInNanoseconds( ) {

	typedef std::chrono::high_resolution_clock		t_clock;
	typedef std::chrono::steady_clock::time_point	time_point;
	
	// ran once initialize a seed time
    static time_point	start = t_clock::now();

    time_point			finish = t_clock::now();

	// convert to nanoseconds, prevent overflow
	return (std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() % UINT32_MAX);

}
