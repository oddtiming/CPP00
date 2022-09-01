#ifndef BRAIN_HPP_
# define BRAIN_HPP_

# include <string>
# include <iostream>

class Brain {

private:
/* Attributes */
	std::string		_ideas[100];

public:
/* Functions */
	Brain( );
	Brain &	operator=( Brain const & rhs );
	Brain( Brain const & src );
	
	~Brain( );
	
	std::string	getIdea( uint index ) const;

};

std::ostream & operator<<( std::ostream & o, Brain const & s );

#endif // BRAIN_HPP_
