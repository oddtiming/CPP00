#include "Student.hpp"

int		main( void ) {

	Student	*students = new Student[42];

	// Do some shit

	delete [] students;
	return 0;
}
