#ifndef BAD_EXAMPLE_HPP_
# define BAD_EXAMPLE_HPP_

# include <iostream>
# include <string>

class Cat {

private:
/* Attributes */
	int		_nbLegs;

public:
/* Functions */
	Cat( );
	Cat( Cat const & src );
	Cat &	operator=( Cat const & rhs );
	~Cat( );

	void	run( int distance );

	void	scornSomeone( std::string const & target );

};

class Pony {

private:
/* Attributes */
	int		_nbLegs;

public:
/* Functions */
	Pony( );
	Pony( Pony const & src );
	Pony &	operator=( Pony const & rhs );
	~Pony( );

	void	run( int distance );

	void	doMagic( std::string const & target );

};

#endif // BAD_EXAMPLE_HPP_
