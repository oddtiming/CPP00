#pragma once

/** GOAL:
 * 		Understanding diff btw class and struct
 */


// This looks exactly like a class... Why do both exist?
// in C++, structs' default scope is public
struct Sample1 {

	int		foo;

	Sample1( void );
	~Sample1( void );

	void	bar( void ) const;
};

// A class's default visibility is private
class Sample2 {

	int		foo;

	Sample2( void );
	~Sample2( void );

	void	bar( void ) const;

};
