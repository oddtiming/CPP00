#ifndef INHER_HPP_
# define INHER_HPP_

# include <string>

class Animal {

private:
/* Attributes */
	int	_nbLegs;

public:
/* Functions */
	Animal( );
	Animal( Animal const & src );
	Animal &	operator=( Animal const & rhs );

	//	All inheriting classes will be able to access these functions
	void	run( int distance );
	void	eat( std::string const & food );
	void	walk( int distance );
	void	call( );

};

// Cat and Pony are Animals

class Cat : public Animal {

public:
/* Functions */
	Cat( );
	Cat( Cat const & src );
	Cat &	operator=( Cat const & rhs );
	~Cat( );

	void	scornSomeone( std::string const & target );

};


class Pony : public Animal {

public:
/* Functions */
	Pony( );
	Pony( Pony const & src );
	Pony &	operator=( Pony const & rhs );
	~Pony( );

	void	doMagic( std::string const & target );

	// can "overload" some functions
	void	run( int distance );


};

std::ostream & operator<<( std::ostream & o, Animal const & s );

#endif // INHER_HPP_
