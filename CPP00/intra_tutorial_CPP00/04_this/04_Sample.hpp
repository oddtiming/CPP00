#pragma once

class Sample {

public:

	// This is a member attribute
	int		foo;

	Sample( void );
	~Sample( void );

	// This is a member function
	// By default, c++ always gives member functions a hidden parameter:
	// a pointer to the current instance!
	void	bar( void );

};
