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

int		nbDigits(long number) {
    int digits = 0;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}
