#pragma once

/** GOAL:
 * 		Understand encapsulation and private vs public
 */
class Sample {

public:

	int		publicFoo;

	Sample( void );
	~Sample( void );

	void	publicBar( void ) const;

// Everything below private can only be accessed from inside the class
private:

	// private attributes should be prefixed by an underscore
	int		_privateFoo;

	void	_privateBar( void ) const;
};

/**
 * @brief 
 * 		Everything that is relevant to the user can be public,
 * 		but you should use private members to abstract as much as possible
 * 
 */
