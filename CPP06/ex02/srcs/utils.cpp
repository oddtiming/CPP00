#include <ctime>
#include <chrono>	 // std::chrono::seconds, std::chrono::steady_clock::time_point, chrono::high_resolution_clock:

typedef std::chrono::high_resolution_clock		t_clock;
typedef std::chrono::steady_clock::time_point	time_point;
// https://www.codegrepper.com/code-examples/cpp/c%2B%2B+time+nanoseconds
long long getTimeInNanoseconds( ) {

	// ran once initialize a seed time
    static time_point	start = t_clock::now();
    time_point			finish = t_clock::now();

	// convert to nanoseconds, prevent overflow
	return (std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() % UINT32_MAX);

}
